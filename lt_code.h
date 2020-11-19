#ifndef LT_CODE_H
#define LT_CODE_H

#include <vector>
#include <algorithm>

#include "packetfactory.h"
#include "packet.h"
#include "utils.h"

class LT_code
{
protected:
    PacketFactory pf;

public:
    LT_code();

    std::vector<Packet> encode (std::string &data);
    std::vector<Packet> encode (char *data);

    std::string decode(std::vector<Packet> &);

    ~LT_code();
};

#endif // LT_CODE_H
