#ifndef JSON_NODE_H
#define JSON_NODE_H
#include <string>
#include <map>
#include "../../common/json_parser/json.hpp"

using json = nlohmann::json;

class JsonNode {
private:
    std::string buffer;
    json j_object;
    void parseStrings(std::map<std::string,std::string> &elements);
public:
    JsonNode(std::map<std::string,std::string> &elements);
    ~JsonNode() = default;
    json* getJsonNode();
};

#endif