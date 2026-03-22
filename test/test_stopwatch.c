#include "test.h"
#include <attotime.h>
#include <unity.h>

static void test_stopwatch_should_start(void) {
  atto_stopwatch_t sw = ATTO_STOPWATCH_INIT;
  TEST_ASSERT_FALSE(atto_stopwatch_started(&sw));
  atto_stopwatch_start(&sw);
  TEST_ASSERT_TRUE(atto_stopwatch_started(&sw));
}

static void test_stopwatch_should_split(void) {
  atto_stopwatch_t sw = ATTO_STOPWATCH_INIT;
  atto_stopwatch_start(&sw);
  TEST_ASSERT_EQUAL_UINT32(0, atto_stopwatch_split(&sw));
  mock_time += 10;
  TEST_ASSERT_EQUAL_UINT32(10, atto_stopwatch_split(&sw));
}

static void test_stopwatch_should_reset(void) {
  atto_stopwatch_t sw = ATTO_STOPWATCH_INIT;
  atto_stopwatch_start(&sw);
  mock_time += 10;
  atto_stopwatch_reset(&sw);
  TEST_ASSERT_FALSE(atto_stopwatch_started(&sw));
  TEST_ASSERT_EQUAL_UINT32(0, atto_stopwatch_split(&sw));
}

static void test_stopwatch_should_copy(void) {
  atto_stopwatch_t sw1 = ATTO_STOPWATCH_INIT;
  atto_stopwatch_start(&sw1);
  mock_time += 5;
  atto_stopwatch_t sw2 = sw1;
  TEST_ASSERT_TRUE(atto_stopwatch_started(&sw2));
  TEST_ASSERT_EQUAL_UINT32(atto_stopwatch_split(&sw1), atto_stopwatch_split(&sw2));
}

static void test_stopwatch_should_handle_overflow(void) {
  mock_time = UINT32_MAX - 5;
  atto_stopwatch_t sw = ATTO_STOPWATCH_INIT;
  atto_stopwatch_start(&sw);
  mock_time += 20;
  TEST_ASSERT_EQUAL_UINT32(20, atto_stopwatch_split(&sw));
}

void testStopwatch(void) {
  RUN_TEST(test_stopwatch_should_start);
  RUN_TEST(test_stopwatch_should_split);
  RUN_TEST(test_stopwatch_should_reset);
  RUN_TEST(test_stopwatch_should_copy);
  RUN_TEST(test_stopwatch_should_handle_overflow);
}
