#pragma once

#include <stdint.h>
#include <stdbool.h>

// System state derived from four BLE connection flags.
// resolveState() maps flags → state using the LED priority order in Docs/LED-States.md
enum SystemState {
    STATE_IDLE,             // nothing connected
    STATE_WATCH_CONNECTED,  // watch connected, RSC not yet subscribed
    STATE_SCANNING,         // RSC subscribed, scanning for treadmill
    STATE_WAITING_FOR_DATA, // both connected, no FTMS data yet
    STATE_TREADMILL_ONLY,   // treadmill connected, watch not subscribed
    STATE_SYSTEM_READY      // fully operational: watch subscribed + data flowing
};

// Flags set exclusively by BLE callbacks (peripheral.cpp and central.cpp).
// Declared volatile because they are written from the BLE event thread and
// read from the loop task thread.
extern volatile bool watchConnected;
extern volatile bool rscSubscribed;
extern volatile bool treadmillConnected;
extern volatile bool dataFlowing;

// Derive the current SystemState from the four flags above.
SystemState resolveState();
