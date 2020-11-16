#ifndef PACKET_H
#define PACKET_H

#include <vector>
#include <random>

#include "distribution.h"

class Packet
{
private:


protected:
    size_t index;
    size_t degree;

    std::string data;

public:
    Packet(char *data, const size_t degree, const size_t id);
    Packet(std::string &data, const size_t degree, const size_t id);

    size_t get_index();
    size_t get_degree();

    std::vector<size_t> gen_neighbors();

    ~Packet();
};

#endif // PACKET_H
