#include "Serial.h"

Serial::Serial(int baudrate) {
    std::string port = findPort();
    setPort(port, baudrate);
    serial = std::fstream(port);
}

std::string Serial::read() {
    std::string out, tmp;
    while (getline(serial, tmp)) out += tmp;
    return out;
}

void Serial::write(std::string data) {
    data += '\n';
    serial.clear();
    serial << data;
    serial.flush();
}

std::string Serial::findPort() {
    std::string base = "/dev/ttyACM";
    int n = 0;
    while (open((base + std::to_string(n)).c_str(), O_RDWR | O_NOCTTY) == -1 && n < 20) n++;
    return base + std::to_string(n);
}

void Serial::setPort(const std::string port, const int baudrate) {
    int device = open(port.c_str(), O_RDWR | O_NOCTTY);
    if (device != 1) {
        struct termios settings;
        memset(&settings, 0, sizeof settings);
        settings.c_cflag = getBaud(baudrate) | CRTSCTS | CS8 | CLOCAL | CREAD & ~PARENB & ~CSTOPB & ~CSIZE | CS8;
        settings.c_iflag = IGNPAR;
        settings.c_oflag |= OPOST;
        settings.c_lflag = 0;
        settings.c_cc[VTIME] = 10;
        settings.c_cc[VMIN] = 0;
        tcflush(device, TCIFLUSH);
        tcsetattr(device, TCSANOW, &settings);
        close(device);
    }
}

speed_t Serial::getBaud(int baudrate) {
    switch (baudrate) {
        case 4800:
            return B4800;
        case 9600:
            return B9600;
        case 19200:
            return B19200;
        case 38400:
            return B38400;
        case 57600:
            return B57600;
        case 115200:
            return B115200;
    }
}
