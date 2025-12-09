/*
 * DM1Handler.cpp
 *
 *  Created on: Dec 3, 2025
 *      Author: nimbus
 */

#include "DM1Handler.h"

bool DM1Handler::parseDM1(const can_frame& f, VehicleStatus& out)
{
    // Byte 0 = Lamp Status 1
    uint8_t lamp = f.data[0];

    out.mil     = decodeLamp((lamp >> 6) & 0x03);
    out.rsl     = decodeLamp((lamp >> 4) & 0x03);
    out.awl     = decodeLamp((lamp >> 2) & 0x03);
    out.pl      = decodeLamp((lamp >> 0) & 0x03);

    // SPN/FMI decode example (first DTC only)
    uint16_t spn_low = f.data[2] | (f.data[3] << 8);
    uint8_t spn_hi   = f.data[4] & 0xE0;
    uint16_t spn = spn_low | (spn_hi << 11);

    uint8_t fmi = f.data[4] & 0x1F;

    out.activeDTC.spn = spn;
    out.activeDTC.fmi = fmi;

    return true;
}

LampStatus DM1Handler::decodeLamp(uint8_t lamp)
{
    switch (lamp)
    {
    case 0: return LampStatus::OFF;
    case 1: return LampStatus::ON;
    case 2: return LampStatus::FLASH;
    default: return LampStatus::OFF;
    }
}
