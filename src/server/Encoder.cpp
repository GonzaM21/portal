#include "Encoder.h"
#define END_MAP "F"

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
        std::to_string(CHELL_HIGH) + "," + std::to_string(chells[i]->getStatus()) +
        "," + std::to_string(chells[i]->getDirection());
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
        "," + std::to_string(size.x) + ","+ std::to_string(0.25);
        this->sender->addMessageToSend(msg);
    }
}

void Encoder :: sendRocks() {
    std::vector<Rock*> rocks = this->data_base->getRocks();
    for ( size_t i = 0; i<rocks.size(); i++ ) {
        std::string msg;
        b2Vec2 pos = rocks[i]->getPosition();
        float size = rocks[i]->getRadius();
        msg = "8," + std::to_string(i+1)+ "," + std::to_string(pos.x) + "," + std::to_string(-pos.y) +
        "," + std::to_string(size) + "," + std::to_string(size);
        this->sender->addMessageToSend(msg);
    }
}

void Encoder :: sendButtons() {
    std::vector<Button*> buttons = this->data_base->getButtons();
    for ( size_t i = 0; i<buttons.size(); i++ ) {
        std::string msg;
        b2Vec2 pos = buttons[i]->getPosition();
        b2Vec2 size = buttons[i]->getSizes();
        int state = buttons[i]->getStatus();
        msg = "4,"+ std::to_string(i+1) +","+std::to_string(pos.x) + "," + std::to_string(-pos.y) +
        "," + std::to_string(size.x) + "," + std::to_string(size.y) + "," +std::to_string(state);
        this->sender->addMessageToSend(msg);
    }
}

void Encoder :: sendEnergyBalls() {
    std::vector<Energy_Ball*> energy_balls = this->data_base->getEnergyBalls();
    for ( size_t i = 0; i<energy_balls.size(); i++ ) {
        std::string msg;
        b2Vec2 pos = energy_balls[i]->getPosition();
        float size = energy_balls[i]->getRadius();
        msg = "7," + std::to_string(pos.x) + "," + std::to_string(-pos.y) +
        "," + std::to_string(2*size) + "," + std::to_string(size) +",0";
        this->sender->addMessageToSend(msg);
    }
}

void Encoder :: sendStoneBlocks() {
    std::vector<Stone_Block*> stone_blocks = this->data_base->getStoneBlocks();
    for ( size_t i = 0; i<stone_blocks.size(); i++ ) {
        std::string msg;
        b2Vec2 pos = stone_blocks[i]->getPosition();
        b2Vec2 size = stone_blocks[i]->getSizes();
        msg = "2,2," + std::to_string(pos.x) + "," + std::to_string(-pos.y) +
        "," + std::to_string(size.x) + "," + std::to_string(size.y);
        this->sender->addMessageToSend(msg);
    }
}

void Encoder :: sendGates() {
    std::vector<Gate*> gates = this->data_base->getGates();
    for ( size_t i = 0; i<gates.size(); i++ ) {
        std::string msg;
        b2Vec2 pos = gates[i]->getPosition();
        b2Vec2 size = gates[i]->getSizes();
        int state = gates[i]->isOpen();
        msg = "3,"+ std::to_string(i+1)+ "," + std::to_string(pos.x) + "," + std::to_string(-pos.y) +
        "," + std::to_string(size.x) + "," + std::to_string(size.y) + "," +std::to_string(state);
        this->sender->addMessageToSend(msg);
    }
}

void Encoder :: sendPortals() {
    std::vector<Chell_Player*> chells = this->data_base->getPlayers();
    for ( size_t i = 0; i<chells.size(); i++ ) {
        for (int portal_num=1; portal_num<3; portal_num++) {
            Portal *portal;
            if (portal_num==1) {
                portal = chells[i]->getPortalIn();
            } else {
                portal = chells[i]->getPortalOut();
            }
            if (portal == nullptr || !portal->isValid()) continue;
            b2Vec2 pos = portal->getPosition();
            b2Vec2 size = portal->getSizes();
            int orientation = portal->getOrientation();
            std::string msg("6,"+std::to_string((i+1+portal_num)*4)+","+ std::to_string(pos.x) + ","
            + std::to_string(-pos.y) + "," + std::to_string(size.x*2) + "," +
            std::to_string(size.y)+","+std::to_string(portal_num)+"," + std::to_string(portal->getOrientation())
            +",1");
            this->sender->addMessageToSend(msg);  
        }
    }
    //Harcodeado la direccion y state
}

void Encoder :: sendBarriers() {
    std::vector<Energy_Barrier*> barriers = this->data_base->getBarriers();
    for ( size_t i = 0; i<barriers.size(); i++ ) {
        std::string msg;
        b2Vec2 pos = barriers[i]->getPosition();
        b2Vec2 size = barriers[i]->getSizes();
        msg = "9,"+ std::to_string(i+1)+ "," + std::to_string(pos.x) + "," + std::to_string(-pos.y) +
        "," + std::to_string(size.x) + "," + std::to_string(size.y);
        this->sender->addMessageToSend(msg);
    }
}

void Encoder :: sendEmitters() {
    std::vector<Energy_Emitters*> emitters = this->data_base->getEmitters();
    for ( size_t i = 0; i<emitters.size(); i++ ) {
        std::string msg;
        b2Vec2 pos = emitters[i]->getPosition();
        b2Vec2 size = emitters[i]->getSizes();
        //emitters[i]->
        msg = "10,"+ std::to_string(i+1)+ "," + std::to_string(pos.x) + "," + std::to_string(-pos.y) +
        "," + std::to_string(size.x) + "," + std::to_string(size.y)+ ",0,0";
        //Direccion y state harcodeados, que hacemos? necesito getters
        this->sender->addMessageToSend(msg);
        this->sendEnergyBall(emitters[i]);
    }
}

void Encoder::sendEnergyBall(Energy_Emitters* emitter) {
    Energy_Ball* ball = emitter->getEnergyBallShoted();
    if (ball == nullptr) return;
    b2Vec2 pos = ball->getPosition();
    float size = ball->getRadius();
    std::string msg;
    msg = "7," + std::to_string(pos.x) + "," + std::to_string(-pos.y) +
    "," + std::to_string(2*size) + "," + std::to_string(size) +",0";
    this->sender->addMessageToSend(msg);
}


void Encoder ::sendWorldSizes() {  //Se necesita?¡?¡?¡?¡?¡?¡?¡¡?
    int width = (int)this->data_base->getWidth();
    for (int i = -30; i<30; i++ ) {
        std::string msg;
        msg = "2,1," + std::to_string(i) + ",1,1,1";
        this->sender->addMessageToSend(msg);
    }
}

void Encoder :: sendEndMap() {
    std::string msg = "F";
    this->sender->addMessageToSend(msg);
}