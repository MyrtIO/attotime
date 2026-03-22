#include "test.h"
#include <attotime.h>
#include <unity.h>

static void test_progress_should_report_state(void) {
  atto_progress_t p = ATTO_PROGRESS_INIT;
  TEST_ASSERT_FALSE(atto_progress_started(&p));
  TEST_ASSERT_FALSE(atto_progress_finished(&p));
  atto_progress_start(&p, 10);
  TEST_ASSERT_TRUE(atto_progress_started(&p));
  TEST_ASSERT_FALSE(atto_progress_finished(&p));
  mock_time += 10;
  TEST_ASSERT_TRUE(atto_progress_started(&p));
  TEST_ASSERT_TRUE(atto_progress_finished(&p));
}

static void test_progress_should_report_value(void) {
  atto_progress_t p = ATTO_PROGRESS_INIT;
  atto_progress_start(&p, 10);
  TEST_ASSERT_EQUAL_UINT8(0, atto_progress_get(&p));
  mock_time += 5;
  TEST_ASSERT_EQUAL_UINT8(127, atto_progress_get(&p));
  mock_time += 5;
  TEST_ASSERT_EQUAL_UINT8(255, atto_progress_get(&p));
}

static void test_progress_should_set_max(void) {
  atto_progress_t p = ATTO_PROGRESS_INIT;
  atto_progress_set_max(&p, 100);
  atto_progress_start(&p, 10);
  mock_time += 5;
  TEST_ASSERT_EQUAL_UINT8(50, atto_progress_get(&p));
  mock_time += 5;
  TEST_ASSERT_EQUAL_UINT8(100, atto_progress_get(&p));
}

static void test_progress_should_copy(void) {
  atto_progress_t p1 = ATTO_PROGRESS_INIT;
  atto_progress_start(&p1, 10);
  atto_progress_t p2 = p1;
  TEST_ASSERT_EQUAL_UINT8(0, atto_progress_get(&p2));
  mock_time += 5;
  TEST_ASSERT_EQUAL_UINT8(127, atto_progress_get(&p2));
  mock_time += 5;
  TEST_ASSERT_EQUAL_UINT8(255, atto_progress_get(&p2));
}

static void test_progress_should_reset(void) {
  atto_progress_t p = ATTO_PROGRESS_INIT;
  atto_progress_start(&p, 10);
  mock_time += 5;
  TEST_ASSERT_GREATER_THAN_UINT8(0, atto_progress_get(&p));
  atto_progress_reset(&p);
  TEST_ASSERT_EQUAL_UINT8(0, atto_progress_get(&p));
}

static void test_progress_should_reset_after_finish(void) {
  atto_progress_t p = ATTO_PROGRESS_INIT;
  atto_progress_start(&p, 10);
  mock_time += 20;
  atto_progress_reset(&p);
  TEST_ASSERT_EQUAL_UINT8(0, atto_progress_get(&p));
}

static void test_progress_should_handle_overflow(void) {
  mock_time = UINT32_MAX - 5;
  atto_progress_t p = ATTO_PROGRESS_INIT;
  atto_progress_start(&p, 10);
  mock_time += 5;
  TEST_ASSERT_EQUAL_UINT8(127, atto_progress_get(&p));
  mock_time += 5;
  TEST_ASSERT_EQUAL_UINT8(255, atto_progress_get(&p));
}

void testProgress(void) {
  RUN_TEST(test_progress_should_report_state);
  RUN_TEST(test_progress_should_report_value);
  RUN_TEST(test_progress_should_set_max);
  RUN_TEST(test_progress_should_copy);
  RUN_TEST(test_progress_should_reset);
  RUN_TEST(test_progress_should_reset_after_finish);
  RUN_TEST(test_progress_should_handle_overflow);
}
