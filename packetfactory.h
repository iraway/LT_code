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

protected:

    std::vector<Packet> packets;

    void parse_data_to_packets(std::string &data);
    size_t gen_degree(const std::vector<double> &);

public:
    static size_t id;

    PacketFactory();
    PacketFactory(std::string &data);
    PacketFactory(char *data);



    ~PacketFactory();
};


#endif // PACKETFACTORY_H
