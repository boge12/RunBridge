#pragma once

#include <stdint.h>
#include <stdbool.h>

// Convert FTMS instantaneous speed (0.01 km/h) to RSC speed (1/256 m/s).
uint16_t ftmsToRscSpeed(uint16_t ftmsRaw);

// Build a complete RSC Measurement packet (0x2A53) into outBuf.
// outBuf must be at least 8 bytes. Returns the number of bytes written.
// Cadence is always 0 — the watch uses its own cadence sensor.
// Includes total distance (flag bit 1) if hasDistance is true.
// Stride length (flag bit 0) is omitted.
uint8_t buildRscPacket(uint8_t* outBuf, uint16_t ftmsSpeedRaw,
                       bool hasDistance, uint32_t distanceM);
