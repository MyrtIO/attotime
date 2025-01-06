#include <unity.h>
#include <Arduino.h>
#include <Attotime.h>

void test_ProgressShouldReportState() {
  Progress progress;
  TEST_ASSERT_FALSE(progress.started());
  TEST_ASSERT_FALSE(progress.finished());
  progress.start(10);
  TEST_ASSERT_TRUE(progress.started());
  TEST_ASSERT_FALSE(progress.finished());
  delay(10);
  TEST_ASSERT_TRUE(progress.started());
  TEST_ASSERT_TRUE(progress.finished());
}

void test_ProgressShouldReportValue() {
  Progress progress;
  progress.start(10);
  TEST_ASSERT_EQUAL(0, progress.get());
  delay(5);
  TEST_ASSERT_INT_WITHIN(100, 128, progress.get());
  delay(5);
  TEST_ASSERT_EQUAL(255, progress.get());
}

void test_ProgressShouldSetMax() {
  Progress progress;
  progress.setMax(100);
  progress.start(10);
  delay(5);
  TEST_ASSERT_INT_WITHIN(50, 50, progress.get());
  delay(5);
  TEST_ASSERT_EQUAL(100, progress.get());
}

void test_ProgressShouldCopy() {
  Progress progress1;
  progress1.start(10);
  Progress progress2;
  progress2 = progress1;
  TEST_ASSERT_EQUAL(0, progress2.get());
  delay(5);
  TEST_ASSERT_INT_WITHIN(100, 128, progress2.get());
  delay(5);
  TEST_ASSERT_EQUAL(255, progress2.get());
}

void test_ProgressShouldReset() {
  Progress progress;
  progress.start(10);
  delay(5);
  TEST_ASSERT_INT_WITHIN(100, 128, progress.get());
  progress.reset();
  TEST_ASSERT_EQUAL(0, progress.get());
}

void test_ProgressShouldResetAfterFinish() {
  Progress progress;
  progress.start(10);
  delay(20);
  progress.reset();
  TEST_ASSERT_EQUAL(0, progress.get());
}

void test_ProgressShouldCompare() {
  Progress progress1;
  Progress progress2;
  TEST_ASSERT_TRUE(progress1 == progress2);
  progress1.start(10);
  TEST_ASSERT_FALSE(progress1 == progress2);
  TEST_ASSERT_TRUE(progress1 != progress2);
  progress2.start(10);
  TEST_ASSERT_TRUE(progress1 == progress2);
  progress1.setMax(100);
  TEST_ASSERT_FALSE(progress1 == progress2);
  progress2.setMax(100);
  TEST_ASSERT_TRUE(progress1 == progress2);

}

void testProgress() {
	RUN_TEST(test_ProgressShouldReportState);
	RUN_TEST(test_ProgressShouldReportValue);
	RUN_TEST(test_ProgressShouldSetMax);
	RUN_TEST(test_ProgressShouldCopy);
	RUN_TEST(test_ProgressShouldReset);
	RUN_TEST(test_ProgressShouldResetAfterFinish);
	RUN_TEST(test_ProgressShouldCompare);
}
