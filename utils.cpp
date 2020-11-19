#include "utils.h"

std::string xor_string(const std::string &f, const std::string &s){
    if(f.length() != s.length()){
        throw new std::exception();
    }
    std::string result;
    result.resize(f.length());
    for(size_t i = 0; i < f.length(); i++){
        result[i] = f[i] ^ s[i];
    }
    return result;
}

bool comparePacketsIndex(Packet &f, Packet &s){
    return f.get_index() < s.get_index();
}

bool comparePacketsDegree(Packet &f, Packet &s){
    return f.get_index() < s.get_index();
}

int vectorWithOne1(const std::vector<size_t> &data){
    size_t sum = 0;
    int ind = -1;
    for(size_t i = 0; i < data.size(); i++){
        sum += data[i];
        if(sum > 1) return -1;
        if(data[i] == 1){
            ind = i;
        }
    }
    return ind;
}
