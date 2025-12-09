/*
 * AppModel.cpp
 *
 *  Created on: Dec 3, 2025
 *      Author: nimbus
 */

#include "AppModel.h"
#include <mutex>

static std::mutex model_mutex;

void AppModel::updateFromJ1939(const VehicleStatus& new_status)
{
    std::lock_guard<std::mutex> lock(model_mutex);
    status.engineSpeed = new_status.engineSpeed;

    status.mil = new_status.mil;
    status.rsl = new_status.rsl;
    status.awl = new_status.awl;
    status.pl  = new_status.pl;

    status.activeDTC = new_status.activeDTC;
}

VehicleStatus AppModel::getStatus() const
{
    std::lock_guard<std::mutex> lock(model_mutex);
    return status;
}
