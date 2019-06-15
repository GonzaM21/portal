#include "json_node.h"
#include <iostream>

JsonNode::JsonNode(std::map<std::string,std::string> &elements) {
    this->parseStrings(elements);
    this->j_object = json::parse(this->buffer);
}

void JsonNode::parseStrings(std::map<std::string,std::string> &elements) {
    this->buffer = "{";
    for (auto it = elements.begin(); it != elements.end(); ++it) { 
        this->buffer = this->buffer + "\""+ (*it).first + "\": " + (*it).second +", ";
    }
    size_t size = this->buffer.length();
    this->buffer = this->buffer.substr(0,size-2)+"}"; 
}

json* JsonNode::getJsonNode() {
    return &this->j_object;
}

