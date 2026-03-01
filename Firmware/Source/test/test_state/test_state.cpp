// Unit tests for resolveState() — compiles for native (no Arduino required).
// Run with: pio test -e native

#include <unity.h>
#include "../../src/state.h"

void setUp() {
    watchConnected     = false;
    rscSubscribed      = false;
    treadmillConnected = false;
    dataFlowing        = false;
}
void tearDown() {}

// TODO: add tests

int main(int argc, char** argv) {
    UNITY_BEGIN();
    // TODO: RUN_TEST(...)
    return UNITY_END();
}
