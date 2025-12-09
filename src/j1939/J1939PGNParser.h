#pragma once
#include <linux/can.h>
#include "../app/AppModel.h"
#include "DM1Handler.h"

struct PGNDecodeResult {
    bool hasValue = false;
    VehicleStatus status;
};   // ← BURASI EKSİKTİ

class J1939PGNParser
{
public:
    PGNDecodeResult decode(const can_frame& f);

private:
    DM1Handler dm1;

    PGNDecodeResult parseDM1(const can_frame& f);
    PGNDecodeResult parseEEC1(const can_frame& f);
};
