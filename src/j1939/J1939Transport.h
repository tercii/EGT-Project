/*
 * J1939Transport.h
 *
 *  Created on: Dec 3, 2025
 *      Author: nimbus
 */

#ifndef SRC_J1939_J1939TRANSPORT_H_
#define SRC_J1939_J1939TRANSPORT_H_

#pragma once
#include <linux/can.h>

class J1939Transport
{
public:
    void handleTp(const can_frame& f);

private:
    void handleBAM(const can_frame& f);
    void handleCTS(const can_frame& f);
    void handleDT(const can_frame& f);
};

#endif /* SRC_J1939_J1939TRANSPORT_H_ */
