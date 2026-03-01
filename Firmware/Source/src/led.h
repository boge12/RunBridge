#pragma once

#include "state.h"

// Initialise LED pins as outputs (active LOW on XIAO nRF52840).
void ledSetup();

// Call every loop() iteration. Non-blocking: uses millis() internally.
// Drives the RGB LED with the pattern corresponding to the given state.
void ledTick(SystemState state);
