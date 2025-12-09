#pragma once
#include <functional>
#include <map>
#include <vector>
#include <string>       // ← EKLENDİ
#include "AppModel.h"

class EventBus
{
public:
    void subscribe(const std::string& event,
                   std::function<void(const VehicleStatus&)> cb);

    void publish(const std::string& event,
                 const VehicleStatus& data);

private:
    std::map<std::string,
             std::vector<std::function<void(const VehicleStatus&)>>> handlers;
};
