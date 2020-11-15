#ifndef IO_H
#define IO_H
#include <string>
#include <iostream>
#include <fstream>

class IO
{
protected:
    std::string path_in;
    std::string path_out;

public:
    IO();
    IO(const char *, const char *);
    IO(const std::string &, const std::string &);

    const char * readData();
    const std::string readDataS();

    void writeData(const char *data);
    void writeData(const std::string &data);

    ~IO();
};

#endif // IO_H
