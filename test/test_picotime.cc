#include <unity.h>
#include <Arduino.h>
#include <Attotime.h>

void test_TimerShouldReportFinish(void) {
  Timer timer;
  timer.start(10);
  TEST_ASSERT_FALSE(timer.finished());
  delay(11);
  TEST_ASSERT_TRUE(timer.finished());
}

void test_StopwatchShouldReportSplit(void) {
  Stopwatch stopwatch;
  stopwatch.start();
  TEST_ASSERT_EQUAL(0, stopwatch.split());
  delay(10);
  TEST_ASSERT_GREATER_THAN(9, stopwatch.split());
}

void test_StopwatchShouldReportStarted(void) {
  Stopwatch stopwatch;
  TEST_ASSERT_FALSE(stopwatch.started());
  stopwatch.start();
  TEST_ASSERT_TRUE(stopwatch.started());
}

void test_ProgressShouldReportFinish(void) {
  Progress progress;
  progress.start(10);
  TEST_ASSERT_FALSE(progress.finished());
  delay(10);
  TEST_ASSERT_TRUE(progress.finished());
}

void test_ProgressShouldReportValue(void) {
  Progress progress;
  progress.start(10);
  TEST_ASSERT_EQUAL(0, progress.get());
  delay(5);
  TEST_ASSERT_INT_WITHIN(100, 128, progress.get());
  delay(5);
  TEST_ASSERT_EQUAL(255, progress.get());
}

void test_ProgressShouldSetMax(void) {
  Progress progress;
  progress.setMax(100);
  progress.start(10);
  delay(5);
  TEST_ASSERT_INT_WITHIN(50, 50, progress.get());
  delay(5);
  TEST_ASSERT_EQUAL(100, progress.get());
}

int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_TimerShouldReportFinish);
  RUN_TEST(test_StopwatchShouldReportSplit);
  RUN_TEST(test_StopwatchShouldReportStarted);
  RUN_TEST(test_ProgressShouldReportFinish);
  RUN_TEST(test_ProgressShouldReportValue);
  RUN_TEST(test_ProgressShouldSetMax);
  return UNITY_END();
}

#ifdef ARDUINO
void setup() {
  runUnityTests();
}
void loop() {}
#else
int main() {
  runUnityTests();
  // print(millis());
  // delay(1000);
  return 0;
}
#endif
