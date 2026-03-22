#include "test.h"
#include <attotime.h>
#include <unity.h>

static void test_timer_should_report_finish(void) {
  atto_timer_t timer = ATTO_TIMER_INIT;
  atto_timer_start(&timer, 10);
  TEST_ASSERT_TRUE(atto_timer_started(&timer));
  TEST_ASSERT_FALSE(atto_timer_finished(&timer));
  mock_time += 10;
  TEST_ASSERT_TRUE(atto_timer_finished(&timer));
}

static void test_timer_should_reset(void) {
  atto_timer_t timer = ATTO_TIMER_INIT;
  atto_timer_start(&timer, 10);
  TEST_ASSERT_TRUE(atto_timer_started(&timer));
  atto_timer_reset(&timer);
  TEST_ASSERT_FALSE(atto_timer_started(&timer));
  TEST_ASSERT_FALSE(atto_timer_finished(&timer));
}

static void test_timer_should_copy(void) {
  atto_timer_t t1 = ATTO_TIMER_INIT;
  atto_timer_start(&t1, 10);
  atto_timer_t t2 = t1;
  TEST_ASSERT_TRUE(atto_timer_started(&t2));
  TEST_ASSERT_FALSE(atto_timer_finished(&t2));
  mock_time += 10;
  TEST_ASSERT_TRUE(atto_timer_finished(&t2));
}

static void test_timer_should_handle_overflow(void) {
  mock_time = UINT32_MAX - 5;
  atto_timer_t timer = ATTO_TIMER_INIT;
  atto_timer_start(&timer, 10);
  TEST_ASSERT_FALSE(atto_timer_finished(&timer));
  mock_time += 10;
  TEST_ASSERT_TRUE(atto_timer_finished(&timer));
}

void testTimer(void) {
  RUN_TEST(test_timer_should_report_finish);
  RUN_TEST(test_timer_should_reset);
  RUN_TEST(test_timer_should_copy);
  RUN_TEST(test_timer_should_handle_overflow);
}
