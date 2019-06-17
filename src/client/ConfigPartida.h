#ifndef __CONFIGPARTIDA_H__
#define __CONFIGPARTIDA_H__

#include <unistd.h>
#include <SDL2/SDL.h>
#include "client/client_communicator.h"
#include "client/Message_sender.h"

class ConfigPartida
{
public:
  ConfigPartida(){};
  ~ConfigPartida(){};
  void setHost(std::string host) {this->host = host;};
  void setPort(std::string port) { this->port = port; };
  void setPlayerName(std::string player_name) { this->player_name = player_name; };
  void setSalaName(std::string sala_name) { this->sala_name = sala_name; }
  void setMode(std::string mode) { this->mode = mode; }
  std::string getHost() {return host;}; 
  std::string getPort() {return port;}; 
  std::string getPlayerName() {return player_name;}; 
  std::string getSalaName() {return sala_name;}; 
  std::string getMode() {return mode;}; 

private: 
  std::string host;
  std::string port;
  std::string player_name;
  std::string sala_name;
  std::string mode;
};

#endif
