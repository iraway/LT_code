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

std::vector<size_t> Packet::gen_neighbors(const size_t number_of_block){
    std::vector<size_t> neighboors;

    std::set<size_t> neigh_set;
    srand (this->index);
    neigh_set.insert(this->index);
    for(size_t i = 1; i < degree; i++){
        while(true){
            size_t neigh = rand() % number_of_block;
            if(neigh_set.find(neigh) != neigh_set.end()) {
                continue;
            }
            neigh_set.insert(neigh);
            break;
        }
    }
    for(auto i = neigh_set.begin(); i != neigh_set.end(); i++){
        neighboors.push_back(*i);
    }
    auto i = std::find(neighboors.begin(), neighboors.end(), this->index);
    iter_swap(i, neighboors.begin());
    return neighboors;
}

size_t Packet::get_index(){
    return this->index;
}

size_t Packet::get_degree(){
    return this->degree;
}

std::string Packet::get_data(){
    return this->data;
}

void Packet::set_data(const std::string &data){
    this->data = data;
}

Packet::~Packet(){}
