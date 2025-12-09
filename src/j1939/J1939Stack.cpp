#include "J1939Stack.h"

J1939Stack::J1939Stack(EventBus& b)
    : bus(b)
{
}

void J1939Stack::onCanFrame(const can_frame& f)
{
    auto result = parser.decode(f);

    if (result.hasValue)
    {
        bus.publish("VehicleStatusUpdated", result.status);
    }
}
