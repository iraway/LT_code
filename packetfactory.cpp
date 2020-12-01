#include "packetfactory.h"

size_t PacketFactory::id = 0;

PacketFactory::PacketFactory(){}

PacketFactory::PacketFactory(std::string &data){
    parse_data_to_packets(data);
}

PacketFactory::PacketFactory(char *data){
    std::string s(data);
    parse_data_to_packets(s);

}

size_t PacketFactory::gen_degree(const std::vector<double> &distrib){
    std::vector<double> intervals;
    for(size_t i = 0; i < distrib.size() + 1; i++){
        intervals.push_back((double)i + 1);
    }
    std::piecewise_constant_distribution<double>
        distribution (intervals.begin(), intervals.end(), distrib.begin());
    int n = distribution(generator);
    return n - 1;
}

std::string PacketFactory::padding(std::string &data){
    if(data.length() % BYTE_IN_PACKET == 0){
        return data;
    }else{
        size_t add = BYTE_IN_PACKET - data.length() % BYTE_IN_PACKET;
        std::string dop;
        dop.resize(add);
        return data + dop;
    }
}

std::vector<Packet> PacketFactory::parse_data_to_packets(std::string &data){
    data = this->padding(data);
    std::vector<double> distrib = dist.robust_distribution(data.length() / BYTE_IN_PACKET * REDUNDANCY);
    //std::vector<double> distrib = dist.ideal_distribution(data.length() / BYTE_IN_PACKET * REDUNDANCY);
    std::string substring = data.substr(0, BYTE_IN_PACKET);
    size_t degree = 1;
    srand(time(NULL));
    Packet packet(substring, rand(), degree, id++);
    packets.push_back(packet);
    for(size_t i = 1; i < REDUNDANCY; i++){
        degree = gen_degree(distrib);
        Packet packet(substring, rand(), degree, id++);
        packets.push_back(packet);
    }
    for(size_t i = 1; i < data.length() / BYTE_IN_PACKET; i++ ){
        substring = data.substr(i * BYTE_IN_PACKET, BYTE_IN_PACKET);
        for(size_t j = 0; j < REDUNDANCY; j++){
            degree = gen_degree(distrib);
            Packet packet(substring, rand(), degree, id++);
            packets.push_back(packet);
        }
    }
    return packets;
}

PacketFactory::~PacketFactory(){}
