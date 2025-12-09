#include "SocketCanDriver.h"
#include <sys/socket.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstring>

SocketCanDriver::SocketCanDriver() {}

SocketCanDriver::~SocketCanDriver() { close(); }

bool SocketCanDriver::open(const std::string& ifname)
{
    sock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (sock < 0) return false;

    struct ifreq ifr {};
    strcpy(ifr.ifr_name, ifname.c_str());
    ioctl(sock, SIOCGIFINDEX, &ifr);

    struct sockaddr_can addr {};
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (::bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0)
        return false;

    running = true;
    rxThread = std::thread(&SocketCanDriver::rxLoop, this);
    return true;
}

void SocketCanDriver::rxLoop()
{
    struct can_frame frame;

    while (running)
    {
        int nbytes = read(sock, &frame, sizeof(frame));
        if (nbytes > 0 && callback)
            callback(frame);
    }
}

bool SocketCanDriver::send(const can_frame& frame)
{
    return write(sock, &frame, sizeof(frame)) == sizeof(frame);
}

void SocketCanDriver::setReceiveCallback(std::function<void(const can_frame&)> cb)
{
    callback = cb;
}

void SocketCanDriver::close()
{
    running = false;
    if (rxThread.joinable())
        rxThread.join();

    if (sock >= 0)
        ::close(sock);
}
