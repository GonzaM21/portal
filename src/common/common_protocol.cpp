#define UINT8_SIZE 1
#define UINT16_SIZE 2
#define UINT32_SIZE 4
#define SIZE 10

#include <arpa/inet.h>
#include <string>
#include "../common/common_protocol.h"

void getSize(uint32_t &total_size, uint32_t &r) {
	if (total_size - r - SIZE > total_size) {
		r = total_size%SIZE;
	} else {
		r = SIZE;
	}
}

Protocol& Protocol :: operator<<(std::string &string) {
	uint32_t size = (uint32_t)string.size();
	uint32_t enviado = 0;
	this->sendInt32(size);
	while (size > enviado && this->socket.isValid()) {
		char cad[SIZE];
		uint32_t e = 0;
		getSize(size,e);
		strncpy(cad, string.data()+enviado,e);
		this->socket.sendMessage(cad,e);
		enviado+=e;
	}
	return *this;
}

Protocol& Protocol :: operator>>(std::string &string) {
	uint32_t size = 0;
	uint32_t recieve = 0;
	this->recieveInt32(&size);
	while (size > recieve && this->socket.isValid()) {
		char buffer[SIZE];
		uint32_t r = 0;
		getSize(size,r);
		this->socket.reciveMessage(buffer,r);
		buffer[r] = '\0';
		string += buffer;
		recieve += r;
	}
	return *this;
}

Protocol :: Protocol(SocketConnect socket) {
	this->socket = std::move(socket);
}

void Protocol::setSocket(SocketConnect socket) {
	this->socket = std::move(socket);
}

Protocol &Protocol ::operator>>(uint8_t &num)
{
	this->socket.reciveMessage((char*)&num,UINT8_SIZE);
	return *this;
}

Protocol& Protocol :: operator>>(uint16_t &num) {
	uint16_t num_r(0);
	this->socket.reciveMessage((char*)&num_r,UINT16_SIZE);
	num = ntohs(num_r);
	return *this;
}

Protocol& Protocol :: operator>>(uint32_t &num) {
	this->recieveInt32(&num);
	return *this;
}

Protocol& Protocol :: operator<<(uint8_t &num) {
	this->socket.sendMessage((char*)&num,UINT8_SIZE);
	return *this;
}

Protocol& Protocol :: operator<<(uint16_t &num) {
	uint16_t num_r = htons(num);
	this->socket.sendMessage((char*)&num_r,UINT16_SIZE);
	return *this;
}

Protocol& Protocol :: operator<<(uint32_t &num) {
	this->sendInt32(num);
	return *this;
}

void Protocol :: sendInt32(uint32_t num) {
	uint32_t num_r = htonl(num);
	this->socket.sendMessage((char*)&num_r,UINT32_SIZE);
}

void Protocol :: recieveInt32(uint32_t *num) {
	uint32_t num_r(0);
	this->socket.reciveMessage((char*)&num_r,UINT32_SIZE);
	*num = ntohl(num_r);
}

void Protocol :: closeProtocol() {
	this->socket.closeConnection();
}
