#pragma once
#include <linux/can.h>
#include "../app/EventBus.h"
#include "J1939PGNParser.h"

class J1939Stack
{
public:
    J1939Stack(EventBus& b);

    void onCanFrame(const can_frame& f);

private:
    EventBus& bus;
    J1939PGNParser parser;
};

