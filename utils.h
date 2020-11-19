#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <exception>

#include "packet.h"

std::string xor_string(const std::string &, const std::string &);

bool comparePacketsIndex(Packet &, Packet &);
bool comparePacketsDegree(Packet &, Packet &);

int vectorWithOne1(const std::vector<size_t> &data);

#endif // UTILS_H
