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
    void write(std::string data);

private:
    std::fstream serial;

    std::string findPort();
    speed_t getBaud(int baudrate);
    void setPort(std::string port, int baudrate);

};


#endif
