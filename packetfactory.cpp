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
    srand(time(NULL));
    int r = rand();
    int last = 0;
    for(size_t i = 0; i < distrib.size(); i++){
        if(r > last && r < INT_MAX * distrib[i]){
            return i + 1;
        }
    }
    return 1;
}

void PacketFactory::parse_data_to_packets(std::string &data){
    std::vector<double> distrib = dist.robust_distribution(data.length() / BYTE_IN_PACKET);
    for(size_t i = 0; i < data.length() / BYTE_IN_PACKET; i += BYTE_IN_PACKET){
        std::string substring = data.substr(i, i + BYTE_IN_PACKET);
        size_t degree = gen_degree(distrib);

        Packet packet(data, degree, id++);
        packets.push_back(packet);
        std::cout << substring << " " << degree << " " << id << std::endl;
    }
    if(data.length() % BYTE_IN_PACKET != 0){
        size_t start = data.length() / BYTE_IN_PACKET * BYTE_IN_PACKET;
        std::string substring = data.substr(start, data.length() - 1);
        size_t degree = gen_degree(distrib);
        Packet packet(data, degree, id++);
        packets.push_back(packet);
        std::cout << substring << " " << degree << " " << id << std::endl;
    }
}

PacketFactory::~PacketFactory(){}
