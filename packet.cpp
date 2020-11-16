#include "packet.h"

Packet::Packet(char *data, const size_t degree, const size_t id) {
    this->data = std::string(data);
    this->index = id;
    this->degree = degree;

}

Packet::Packet(std::string &data, const size_t degree, const size_t id){
    this->data = data;
    this->index = id;
    this->degree = degree;
}

std::vector<size_t> Packet::gen_neighbors(){
    srand (this->index);
    //this->degree =
    return std::vector<size_t>();
}

size_t Packet::get_index(){
    return this->index;
}

size_t Packet::get_degree(){
    return this->degree;
}

Packet::~Packet(){}
