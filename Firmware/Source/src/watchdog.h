#pragma once

#include <stdint.h>

// Configure and start the nRF52840 hardware watchdog.
// timeoutMs: reset if wdtFeed() is not called within this many milliseconds.
void wdtInit(uint32_t timeoutMs);

// Pet the watchdog. Call every loop() iteration.
void wdtFeed();
