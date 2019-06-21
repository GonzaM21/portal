#ifndef MATCH_CONFIGURATION_H__
#define MATCH_CONFIGURATION_H__

#include <unistd.h>
#include <SDL2/SDL.h>
#include "client_communicator.h"
#include "Message_sender.h"

class MatchConfig {
public:
  MatchConfig(){};
  ~MatchConfig(){};
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
