#include <string.h>
#include <string>
#include <iostream>
#include "../common/common_socket_connect.h"
#include "../common/common_error.h"

void SocketConnect :: set_hints_socket() {
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;     
	hints.ai_socktype = SOCK_STREAM; 
	hints.ai_flags = 0;  	
}

SocketConnect :: SocketConnect() {
	s = -1;
	skt = -1;
}

SocketConnect :: SocketConnect(int socket) {
	s = -1;  
	skt = socket;
}

bool SocketConnect :: addrinfo(const char *hostn,const char *srvn) {
	set_hints_socket();
	s = getaddrinfo(hostn, srvn, &hints, &result);
   	if (s != 0) { 
      		printf("Error in getaddrinfo: %s\n", gai_strerror(s));
			Error error;
			error.disconnection_error();
      		return false;
   	}
   	return true;	
}

bool SocketConnect :: socketConnect() {
	bool establish_connection = false;
	for (ptr = result; ptr!=NULL && !establish_connection; 
		ptr=ptr->ai_next) {
			skt = socket(ptr->ai_family, ptr->ai_socktype,
				ptr->ai_protocol);
			if (skt == -1) {
					printf("Error: %s\n", strerror(errno));
			} else {
				s = connect(skt, ptr->ai_addr,ptr->ai_addrlen);
				if (s == -1) {
					printf("Error: %s\n", strerror(errno));
					close(skt);
			}
			establish_connection = (s != -1);
		}	
  }
	freeaddrinfo(result); 
	if (establish_connection == false) {
		Error error;
		error.disconnection_error();
		return false;
	}
	return true;
}


int SocketConnect :: reciveMessage(char *buf,int size) {
	int recived = 0, r= 0;
	bool socket_is_valid = true;
	while (recived < size && socket_is_valid) {
		r = recv(skt, &buf[recived], size-recived, MSG_NOSIGNAL);
		if (r <= 0) {
			socket_is_valid = false;
		} else {
			recived += r;
		}
	}
	if (socket_is_valid) {
		return recived;
	} else {
		Error error;
		error.disconnection_error();
		return -1;
	}
}

int SocketConnect :: sendMessage(char *buf,int size) { 
	int total = 0,s= 0;
	bool socket_is_valid = true;
	while (total < size && socket_is_valid) {
		s = send(skt, &buf[total], size-total, MSG_NOSIGNAL); 
		if (s <= 0) {
			socket_is_valid = false;
		} else {
			total += s;
		}
	}
	if (socket_is_valid) {
		return total;
	} else {
		Error error;
		error.disconnection_error();
		return -1;
	}
}

void SocketConnect :: closeConnection() {
	shutdown(skt, SHUT_RDWR);
	this->skt = -1;
	this->s = -1;
}

SocketConnect :: SocketConnect(SocketConnect&& other) {
    this->s = std::move(other.s);
	this->skt = std::move(other.skt);
	other.skt = -1;
	other.s = -1;
}

SocketConnect& SocketConnect :: operator=(SocketConnect&& other) {
    this->s = std::move(other.s);
	this->skt = std::move(other.skt);
	other.skt = -1;
	other.s = -1;
    return *this;
}

bool SocketConnect :: isValid(){
	return this->skt != -1;
}