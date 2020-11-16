#include <iostream>
#include <algorithm>
#include <iterator>

#include "io.h"
#include "distribution.h"
#include "packetfactory.h"

void test(std::string file_in, std::string file_out);

int main(int argc, char **argv)
{

    if(argc != 3){
        std::cout << "[file_in] [file_out]" << std::endl;
        return -1;
    }

    const char *file_in = argv[1];
    const char *file_out = argv[2];

    test(std::string(file_in), std::string(file_out));

    return 0;
}


void test(std::string file_in, std::string file_out){
    IO io(file_in, file_out);
    std::string source_data = io.readDataS();

    PacketFactory pf(source_data);


}
