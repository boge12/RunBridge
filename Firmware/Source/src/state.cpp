#include "state.h"

volatile bool watchConnected     = false;
volatile bool rscSubscribed      = false;
volatile bool treadmillConnected = false;
volatile bool dataFlowing        = false;

SystemState resolveState() {
    // TODO: implement
    return STATE_IDLE;
}
