#pragma once

// === Hardware (active LOW on XIAO nRF52840) ===
#define LED_RED   11
#define LED_GREEN 12
#define LED_BLUE  13

// === BLE UUIDs (16-bit, standard) ===
#define UUID16_RSC_SERVICE          0x1814
#define UUID16_RSC_MEASUREMENT      0x2A53
#define UUID16_RSC_FEATURE          0x2A54
#define UUID16_FTMS_SERVICE         0x1826
#define UUID16_FTMS_TREADMILL_DATA  0x2ACD

// === Timing (milliseconds) ===
#define WDT_TIMEOUT_MS              8000
#define LED_SLOW_BLINK_PERIOD_MS    2000
#define LED_FAST_BLINK_PERIOD_MS     300
#define LED_DOUBLE_BLINK_PERIOD_MS  2000

// === FTMS Treadmill Data flags (bit positions per BT spec) ===
#define FTMS_FLAG_MORE_DATA         (1 << 0)
#define FTMS_FLAG_AVG_SPEED         (1 << 1)
#define FTMS_FLAG_TOTAL_DISTANCE    (1 << 2)
#define FTMS_FLAG_INCLINATION       (1 << 3)
#define FTMS_FLAG_ELEVATION         (1 << 4)
#define FTMS_FLAG_PACE              (1 << 5)
#define FTMS_FLAG_ENERGY            (1 << 6)
#define FTMS_FLAG_HEART_RATE        (1 << 7)
#define FTMS_FLAG_METABOLIC         (1 << 8)
#define FTMS_FLAG_ELAPSED_TIME      (1 << 9)
#define FTMS_FLAG_REMAINING_TIME    (1 << 10)

// === RSC Measurement flags ===
#define RSC_FLAG_STRIDE_LENGTH      (1 << 0)
#define RSC_FLAG_TOTAL_DISTANCE     (1 << 1)

// === Cadence estimation curve (speed in 0.01 km/h, cadence in strides/min) ===
// Defined as a static array in rsc.cpp
// Points: {0, 0}, {800, 160}, {1200, 170}, {1600, 180}
