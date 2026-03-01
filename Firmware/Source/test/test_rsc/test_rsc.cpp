// Unit tests for ftmsToRscSpeed() and buildRscPacket().
// Run with: pio test -e native

#include <unity.h>
#include "../../src/rsc.h"
#include "../../src/config.h"

void setUp() {}
void tearDown() {}

void test_ftmsToRscSpeed_zero() {
    TEST_ASSERT_EQUAL_UINT16(0, ftmsToRscSpeed(0));
}

void test_ftmsToRscSpeed_10kph() {
    // 1000 * 256 / 360 = 711
    TEST_ASSERT_EQUAL_UINT16(711, ftmsToRscSpeed(1000));
}

void test_ftmsToRscSpeed_8kph() {
    // 800 * 256 / 360 = 568
    TEST_ASSERT_EQUAL_UINT16(568, ftmsToRscSpeed(800));
}

void test_buildRscPacket_cadence_is_zero() {
    uint8_t buf[10] = {0};
    buildRscPacket(buf, 1000, false, 0);
    // Byte 3 is cadence — must always be 0 (watch provides its own)
    TEST_ASSERT_EQUAL_UINT8(0, buf[3]);
}

void test_buildRscPacket_no_distance_length() {
    uint8_t buf[10] = {0};
    uint8_t len = buildRscPacket(buf, 1000, false, 0);
    TEST_ASSERT_EQUAL_UINT8(4, len);  // flags + speed(2) + cadence
}

void test_buildRscPacket_with_distance_length() {
    uint8_t buf[10] = {0};
    uint8_t len = buildRscPacket(buf, 1000, true, 500);
    TEST_ASSERT_EQUAL_UINT8(8, len);  // flags + speed(2) + cadence + distance(4)
}

void test_buildRscPacket_distance_flag_set() {
    uint8_t buf[10] = {0};
    buildRscPacket(buf, 1000, true, 0);
    TEST_ASSERT_BITS(RSC_FLAG_TOTAL_DISTANCE, RSC_FLAG_TOTAL_DISTANCE, buf[0]);
}

void test_buildRscPacket_distance_flag_clear() {
    uint8_t buf[10] = {0};
    buildRscPacket(buf, 1000, false, 0);
    TEST_ASSERT_BITS(RSC_FLAG_TOTAL_DISTANCE, 0, buf[0]);
}

int main(int argc, char** argv) {
    UNITY_BEGIN();
    RUN_TEST(test_ftmsToRscSpeed_zero);
    RUN_TEST(test_ftmsToRscSpeed_10kph);
    RUN_TEST(test_ftmsToRscSpeed_8kph);
    RUN_TEST(test_buildRscPacket_cadence_is_zero);
    RUN_TEST(test_buildRscPacket_no_distance_length);
    RUN_TEST(test_buildRscPacket_with_distance_length);
    RUN_TEST(test_buildRscPacket_distance_flag_set);
    RUN_TEST(test_buildRscPacket_distance_flag_clear);
    return UNITY_END();
}
