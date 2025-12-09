/*
 * EventBus.cpp
 *
 *  Created on: Dec 3, 2025
 *      Author: nimbus
 */

#include "EventBus.h"

void EventBus::subscribe(const std::string& event,
                         std::function<void(const VehicleStatus&)> cb)
{
    handlers[event].push_back(cb);
}

void EventBus::publish(const std::string& event,
                       const VehicleStatus& data)
{
    if (!handlers.count(event))
        return;

    for (auto& cb : handlers[event])
        cb(data);
}
