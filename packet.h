#ifndef PACKET_H
#define PACKET_H

#include <vector>
#include <random>
#include <algorithm>

#include "distribution.h"

class Packet
{
private:

protected:
    size_t index;

    size_t index_for_degree;
    size_t degree;

    std::string data;

public:
    Packet(char *data, const size_t index_for_degree, const size_t degree, const size_t id);
    Packet(std::string &data, const size_t index_for_degree, const size_t degree, const size_t id);

    size_t get_index();
    size_t get_degree();
    std::string get_data();

    void set_data(const std::string &);

    std::vector<size_t> gen_neighbors(const size_t number_of_block);

    ~Packet();
};

#endif // PACKET_H
