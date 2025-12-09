#pragma once
#include <cstdint>

enum class LampStatus { OFF = 0, ON = 1, FLASH = 2 };

struct ActiveDTC
{
    uint32_t spn = 0;
    uint8_t  fmi = 0;
};

struct VehicleStatus
{
    float engineSpeed = 0;

    LampStatus mil = LampStatus::OFF;
    LampStatus rsl = LampStatus::OFF;
    LampStatus awl = LampStatus::OFF;
    LampStatus pl  = LampStatus::OFF;

    ActiveDTC activeDTC;
};

class AppModel
{
public:
    // J1939 → AppModel
    void updateFromJ1939(const VehicleStatus& new_status);

    // GUI → copy of model data
    VehicleStatus getStatus() const;

private:
    VehicleStatus status;
};
