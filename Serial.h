#ifndef SERIAL_H
#define SERIAL_H

#include <cstring>
#include <string>
#include <fstream>

#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

class Serial {
public:
    Serial(int baudrate);

    std::string read();
    void write(std::string &data);

private:
    std::fstream serial;

    std::string findPort(const std::string &base);
    speed_t getBaud(int baudrate);
    void setPort(const std::string &port, const int baudrate);

};


#endif
