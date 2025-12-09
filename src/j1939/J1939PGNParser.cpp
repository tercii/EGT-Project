#include "J1939PGNParser.h"

PGNDecodeResult J1939PGNParser::decode(const can_frame& f)
{
    uint32_t pgn = (f.can_id >> 8) & 0xFFFF;

    switch (pgn)
    {
    case 0xF004:  // EEC1
        return parseEEC1(f);
    default:
        return {};
    }
}

PGNDecodeResult J1939PGNParser::parseEEC1(const can_frame& f)
{
    PGNDecodeResult r;
    r.hasValue = true;

    uint16_t rpm_raw = f.data[3] | (f.data[4] << 8);
    r.status.engineSpeed = rpm_raw * 0.125f;

    return r;
}
