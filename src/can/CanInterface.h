#pragma once
#include <linux/can.h>
#include <functional>
#include <string>      // ← EKLENDİ

class CanInterface {
public:
    virtual ~CanInterface() = default;

    virtual bool open(const std::string& ifname) = 0;
    virtual bool send(const can_frame& frame) = 0;
    virtual void setReceiveCallback(std::function<void(const can_frame&)> cb) = 0;
    virtual void close() = 0;
};
