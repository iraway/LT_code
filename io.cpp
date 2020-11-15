#include "io.h"

IO::IO() {}

IO::IO(const char *path_in, const char *path_out){
    this->path_in = std::string(path_in);
    this->path_out = std::string(path_out);
}

IO::IO(const std::string &path_in, const std::string &path_out){
    this->path_in = path_in;
    this->path_out = path_out;
}

const char * IO::readData(){
    return this->readDataS().data();
}

const std::string IO::readDataS(){
    std::ifstream t(this->path_in);
    return std::string((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());
    //return content;
}

void IO::writeData(const char *data){
    this->writeData(std::string(data));
}

void IO::writeData(const std::string &data){
    std::ofstream file (this->path_out);
    if(file.is_open()){
        file << data;
    }
    file.close();
}

IO::~IO(){}
