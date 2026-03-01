#pragma once

#include <stdint.h>
#include <stdbool.h>

// Parsed data extracted from an FTMS Treadmill Data notification (0x2ACD).
struct FtmsData {
    uint16_t instantSpeedRaw; // speed in 0.01 km/h units (e.g. 1000 = 10.00 km/h)
    bool     hasDistance;     // true if total distance field was present in packet
    uint32_t totalDistanceM;  // total distance in whole meters (uint24 from spec)
    bool     valid;           // false if packet was too short or malformed
};

// Parse a raw FTMS Treadmill Data notification buffer.
// data: pointer to notification payload, len: payload length in bytes.
// Returns a FtmsData struct; check .valid before using other fields.
FtmsData parseFtmsPacket(const uint8_t* data, uint16_t len);
