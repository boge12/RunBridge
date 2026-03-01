#pragma once

#include <stdint.h>
#include <stdbool.h>

// Convert FTMS instantaneous speed (0.01 km/h) to RSC speed (1/256 m/s).
uint16_t ftmsToRscSpeed(uint16_t ftmsRaw);

// Estimate running cadence (strides/min) from treadmill speed using a
// piecewise-linear curve: 0→0, 8 km/h→160, 12 km/h→170, 16+ km/h→180.
uint8_t estimateCadence(uint16_t ftmsRaw);

// Build a complete RSC Measurement packet (0x2A53) into outBuf.
// outBuf must be at least 10 bytes. Returns the number of bytes written.
// Includes total distance (flag bit 1) if hasDistance is true.
// Stride length (flag bit 0) is omitted in this implementation.
uint8_t buildRscPacket(uint8_t* outBuf, uint16_t ftmsSpeedRaw,
                       bool hasDistance, uint32_t distanceM);
