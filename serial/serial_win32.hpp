#pragma once

#include "serial.hpp"
#include <string>
#include <windows.h>

class serial_win32 : public serial
{
public:
    serial_win32(const std::string &port_name, size_t baudrate = 115200,
        size_t databits = 8, parity parity = parity::NONE,
        stopbits stopbits = stopbits::ONE, flowctrl flowctrl = flowctrl::NONE);
    ~serial_win32();
    
    std::vector<char> read() override;
    void write(const std::vector<char> &data) override;
    void write(const char *data) override;
    void write(char data) override;
    
private:
    HANDLE port_handle;
};
