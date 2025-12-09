/*
 * J1939Tansport.cpp
 *
 *  Created on: Dec 3, 2025
 *      Author: nimbus
 */

#include "J1939Transport.h"
#include <iostream>
#include <cstdint>

void J1939Transport::handleTp(const can_frame& f)
{
    uint8_t control = f.data[0];

    switch (control)
    {
    case 0x20: handleBAM(f); break;
    case 0x11: handleCTS(f); break;
    case 0x10: handleDT(f);  break;
    default: break;
    }
}

void J1939Transport::handleBAM(const can_frame& f)
{
    std::cout << "TP.BAM received\n";
}

void J1939Transport::handleCTS(const can_frame& f)
{
    std::cout << "TP.CTS received\n";
}

void J1939Transport::handleDT(const can_frame& f)
{
    std::cout << "TP.DT received\n";
}



