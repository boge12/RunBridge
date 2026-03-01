#pragma once

// Initialise BLE central callbacks. Does NOT start scanning immediately.
// Must be called from setup() AFTER Bluefruit.begin(1, 1).
void centralSetup();

// Begin scanning for an FTMS treadmill (UUID 0x1826).
// Called by peripheral.cpp when the watch subscribes to RSC notifications.
void centralStartScan();

// Stop scanning (called when RSC subscription is lost).
void centralStopScan();
