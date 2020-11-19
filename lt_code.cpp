#include "lt_code.h"

LT_code::LT_code() {}

std::vector<Packet> LT_code::encode (std::string &data){
    if(data.length() >= MAX_SIZE_OF_FILE){
        std::cout << "Sorry, file is too big." << std::endl;
        return std::vector<Packet>();
    }
    std::vector<Packet> packets = pf.parse_data_to_packets(data);
    std::sort(packets.begin(), packets.end(), comparePacketsIndex);
    size_t num_of_packets = packets.size();

    std::vector<Packet> result;
    for(size_t i = 0; i < num_of_packets; i++){
        Packet packet = packets[i];
        std::vector<size_t> neighbors = packet.gen_neighbors(num_of_packets);
        std::string packet_data = packet.get_data();
        for(size_t i = 1; i < neighbors.size(); i++){
            std::string t = packets[neighbors[i]].get_data();
            packet_data = xor_string(packet_data, packets[neighbors[i]].get_data());
        }
        packet.set_data(packet_data);
        result.push_back(packet);
    }
    return result;
}

std::vector<Packet> LT_code::encode (char *data){
    std::string dS(data);
    return this->encode(dS);
}

std::string LT_code::decode(std::vector<Packet> &packets){
    std::sort(packets.begin(), packets.end(), comparePacketsIndex);
    size_t num_of_packets = packets.size();

    std::vector<std::vector<size_t>> matrix;
    matrix.resize(num_of_packets);
    for(size_t i = 0; i < num_of_packets; i++){
        matrix[i].resize(num_of_packets);
        std::vector<size_t> neib = packets[i].gen_neighbors(num_of_packets);
        for(size_t j = 0; j < neib.size(); j++){
            matrix[i][neib[j]]++;
        }
    }


    //Adjacency matrix for debuging
    for(size_t i = 0; i < num_of_packets; i++){
        for(size_t j = 0; j < num_of_packets; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    std::set<size_t> ones_row;
    size_t count_one = 0;
    for(size_t i = 0; i < num_of_packets; i++){
        if(std::find(ones_row.begin(), ones_row.end(), i) == ones_row.end()){
            int k = vectorWithOne1(matrix[i]);
            if(k >= 0){
                count_one++;
                ones_row.insert(i);
                for(int j = 0; j < num_of_packets; j++){
                    if(matrix[j][k] == 1 && j != k){
                        if(std::find(ones_row.begin(), ones_row.end(), j) == ones_row.end()){
                            packets[j].set_data(xor_string(packets[j].get_data(), packets[i].get_data()));
                            matrix[j][k] = 0;
                        }
                    }
                }
                i = 0;
                matrix[i][k] = 0;
            }
        }
    }
    //std::string result;
    //for(size_t i = 0; i < num_of_packets; i++){
    //    result += packets[i].get_data();
    //}

    //std::cout << count_one << " is a number of ones row" << std::endl;
    //std::cout << (double)count_one / num_of_packets * 100 << " % of decode symbols" << std::endl;

    return deleteDuplicates(packets);
}

std::string LT_code::deleteDuplicates(std::vector<Packet> &data){
    std::string result;

    for(size_t i = 0; i < data.size(); i += REDUNDANCY){
        std::map<std::string,int> counter;
        size_t max_c = 0;
        std::string temp;
        bool no_map = false;
        for(size_t j = i; j < i + REDUNDANCY; j++){
            if(data[j].get_degree() == 1){
                temp = data[j].get_data();
                no_map = true;
                break;
            }
            auto it = counter.find(data[j].get_data());
            if (it != counter.end()){
                it->second++;
            }else{
                counter.insert(std::pair<std::string, int>(data[j].get_data(), 1));
            }
        }
        if(!no_map){
            for(auto it = counter.begin(); it != counter.end(); it++){
                if(it->second > max_c){
                   max_c = it->second;
                   temp = it->first;
                }
            }
        }
        result += temp;
    }
    return result;
}

LT_code::~LT_code(){}
