#include "rsc.h"
#include "config.h"

uint16_t ftmsToRscSpeed(uint16_t ftmsRaw) {
    // FTMS: 0.01 km/h → RSC: 1/256 m/s
    // 0.01 km/h = 1/360 m/s, so rscSpeed = ftmsRaw * 256 / 360
    return (uint16_t)((uint32_t)ftmsRaw * 256 / 360);
}

uint8_t buildRscPacket(uint8_t* outBuf, uint16_t ftmsSpeedRaw,
                       bool hasDistance, uint32_t distanceM) {
    uint8_t flags = 0;
    if (hasDistance) flags |= RSC_FLAG_TOTAL_DISTANCE;

    uint16_t rscSpeed = ftmsToRscSpeed(ftmsSpeedRaw);

    uint8_t idx = 0;
    outBuf[idx++] = flags;
    outBuf[idx++] = (uint8_t)(rscSpeed & 0xFF);
    outBuf[idx++] = (uint8_t)(rscSpeed >> 8);
    outBuf[idx++] = 0;  // Cadence: 0 defers to watch's own cadence sensor

    if (hasDistance) {
        outBuf[idx++] = (uint8_t)(distanceM & 0xFF);
        outBuf[idx++] = (uint8_t)((distanceM >> 8) & 0xFF);
        outBuf[idx++] = (uint8_t)((distanceM >> 16) & 0xFF);
        outBuf[idx++] = (uint8_t)((distanceM >> 24) & 0xFF);
    }

    return idx;
}
