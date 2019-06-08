#include "Encoder.h"

Encoder :: Encoder(ProtectedDataBase *data_base,Sender *sender) {
    this->data_base = data_base;
    this->sender = sender;
}

void Encoder :: sendPlayerIds() {
    int id(1);
    std::vector<std::string> ids = this->data_base->getIds();
    for (size_t i = 0; i<ids.size(); i++) {
        std::string msg;
        msg = "0," + std::to_string(id);
        this->sender->sendMessageTo(ids[i],msg);
        id++;      
    }  
}

void Encoder :: sendPlayersPositions() {
    int id(1);
    std::vector<Chell_Player*> chells = this->data_base->getPlayers();
    for ( size_t i = 0; i<chells.size(); i++ ) {
        b2Vec2 position = chells[i]->getPosition();
        std::string msg = "1,"+std::to_string(id)+ "," + std::to_string(position.x) + "," + 
        std::to_string(-position.y) + "," + std::to_string(CHELL_WIDTH)+ "," + 
        std::to_string(CHELL_HIGH);
        this->sender->addMessageToSend(msg);
        id++;        
    }  
}

void Encoder :: sendMetalBlocks() {
    std::vector<Metal_Block*> metal_blocks = this->data_base->getMetalBlocks();
    for ( size_t i = 0; i<metal_blocks.size(); i++ ) {
        std::string msg;
        b2Vec2 pos = metal_blocks[i]->getPosition();
        b2Vec2 size = metal_blocks[i]->getSizes();
        msg = "2,1," + std::to_string(pos.x) + "," + std::to_string(-pos.y) +
        "," + std::to_string(size.x) + "," + std::to_string(size.y);
        this->sender->addMessageToSend(msg);
    }
}

void Encoder :: sendAcids() {
    std::vector<Acid*> acids = this->data_base->getAcids();
    for ( size_t i = 0; i<acids.size(); i++ ) {
        std::string msg;
        b2Vec2 pos = acids[i]->getPosition();
        b2Vec2 size = acids[i]->getSizes();
        msg = "5,"+ std::to_string(pos.x) + "," + std::to_string(-pos.y) +
        "," + std::to_string(size.x) + ","+ std::to_string(size.y);
        this->sender->addMessageToSend(msg);
    }
}


void Encoder ::sendWorldSizes() {  //Se necesita?¡?¡?¡?¡?¡?¡?¡¡?
    int width = (int)this->data_base->getWidth();
    for (int i = -10; i<20; i++ ) {
        std::string msg;
        msg = "2,1," + std::to_string(i) + ",1,1,1";
        this->sender->addMessageToSend(msg);
    }
}