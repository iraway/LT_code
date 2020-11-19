#ifndef PACKETFACTORY_H
#define PACKETFACTORY_H

#include <vector>
#include <random>
#include <ctime>
#include <bits/stdc++.h>

#include "packet.h"
#include "constants.h"

class PacketFactory
{
private:
    Distribution dist;
    std::default_random_engine generator;
protected:
    static size_t id;

    std::vector<Packet> packets;

    size_t gen_degree(const std::vector<double> &);
    std::string padding(std::string &data);

public:
    PacketFactory();
    PacketFactory(std::string &data);
    PacketFactory(char *data);

    std::vector<Packet> parse_data_to_packets(std::string &data);

    ~PacketFactory();
};


#endif // PACKETFACTORY_H
