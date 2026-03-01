#pragma once

// Initialise the RSC GATT service, characteristics, and BLE advertising.
// Must be called from setup() AFTER Bluefruit.begin(1, 1).
void peripheralSetup();

// Notify the connected watch with a pre-built RSC Measurement packet.
// Safe to call from any thread; returns false if watch is not subscribed.
bool sendRscNotification(const uint8_t* data, uint8_t len);
