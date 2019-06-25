#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H
#include <map>
#include <list>
#include <string>
#include <vector>
#include "level_creator/map_parser.h"
#include "server_model.h"
#define NO_VOTE_YET 0
#define VOTE_YES 1
#define VOTE_NO 2
#define WAITING 0
#define PLAY_NEXT_LEVEL 1
#define NO_PLAY_NEXT_LEVEL 2

class LevelManager {
private:
    std::vector<std::string> json_files;
    size_t actual_level;
    std::list<int> player_votes;
    std::map<std::string,bool>* players_online;
    MapParser map_parser;
    Model *model;
    void setVotes();
    void restartModel();
    void restartGameLoop();
    void loadLevel();
public:
    LevelManager(Model *model, std::map<std::string,bool>* players_online);
    ~LevelManager() = default;

    //Setea el voto de un jugador para jugador o 
    //no el proximo nivel
    void managePlayerVote(int vote); //VOY A TENER QUE VOTAR QUE NO CUANDO UN JUGADOR SE DESCONECTA, LO QYUE PUEDO HACER ES QUE EL CLIENTE YA MANDE UN VOTO NO CUANDO SE DESCONECTA

    //Carga el siguiente nivel en el modelo, tomando
    //nombre de archivo el string que halla en la lista
    void loadNextLevel();

    //Devuelve si el proximo nivel se va jugar, no se va jugar
    //o si se debe esperar a que terminen de votar los jugadores.
    int playersAcceptNextLevel();

    //Devuelve un booleano indicando si ya se terminaron
    //los niveles para jugar
    bool allLevelPlayed();

    void loadFirstLevel();

    void addPlayersToNewLevel();

    int getNumberOfLevels();
};

#endif