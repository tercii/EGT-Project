/*
 * SocketCanDriver.h
 *
 *  Created on: Dec 3, 2025
 *      Author: nimbus
 */

#ifndef SRC_CAN_SOCKETCANDRIVER_H_
#define SRC_CAN_SOCKETCANDRIVER_H_
#pragma once
#include "CanInterface.h"
#include <string>
#include <thread>
#include <atomic>

class SocketCanDriver : public CanInterface
{
public:
    SocketCanDriver();
    ~SocketCanDriver();

    bool open(const std::string& ifname) override;
    bool send(const can_frame& frame) override;
    void setReceiveCallback(std::function<void(const can_frame&)> cb) override;
    void close() override;

private:
    int sock = -1;
    std::function<void(const can_frame&)> callback;
    std::thread rxThread;
    std::atomic<bool> running{false};

    void rxLoop();
};

#endif /* SRC_CAN_SOCKETCANDRIVER_H_ */
