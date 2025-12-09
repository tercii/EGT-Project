/*
 * DM1Handler.h
 *
 *  Created on: Dec 3, 2025
 *      Author: nimbus
 */

#ifndef SRC_J1939_DM1HANDLER_H_
#define SRC_J1939_DM1HANDLER_H_

#pragma once
#include <linux/can.h>
#include "../app/AppModel.h"

class DM1Handler
{
public:
    DM1Handler() = default;

    bool parseDM1(const can_frame& f, VehicleStatus& out);

private:
    LampStatus decodeLamp(uint8_t lamp);
};

#endif /* SRC_J1939_DM1HANDLER_H_ */
