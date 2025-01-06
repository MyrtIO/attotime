#include <unity.h>
#include <Arduino.h>
#include <Attotime.h>

void test_StopwatchShouldStart() {
	Stopwatch stopwatch;
	TEST_ASSERT_FALSE(stopwatch.started());
	stopwatch.start();
	TEST_ASSERT_TRUE(stopwatch.started());
}

void test_StopwatchShouldSplit() {
	Stopwatch stopwatch;
	stopwatch.start();
	TEST_ASSERT_EQUAL_UINT32(0, stopwatch.split());
	delay(10);
	TEST_ASSERT_GREATER_THAN_UINT32(0, stopwatch.split());
}

void test_StopwatchShouldCompare() {
	Stopwatch stopwatch1;
	Stopwatch stopwatch2;

	TEST_ASSERT_TRUE(stopwatch1 == stopwatch2);
	stopwatch1.start();
	TEST_ASSERT_FALSE(stopwatch1 == stopwatch2);
	TEST_ASSERT_TRUE(stopwatch1 != stopwatch2);
	stopwatch1.reset();
	stopwatch2.reset();

	TEST_ASSERT_TRUE(stopwatch1 == stopwatch2);
}

void test_StopwatchShouldAssign() {
    Stopwatch stopwatch1;
    Stopwatch stopwatch2;
    stopwatch1.start();
    delay(5);
    stopwatch2 = stopwatch1;
    TEST_ASSERT_TRUE(stopwatch2.started());
    TEST_ASSERT_EQUAL_UINT32(stopwatch1.split(), stopwatch2.split());
	TEST_ASSERT_TRUE(stopwatch1 == stopwatch2);
	TEST_ASSERT_FALSE(stopwatch1 != stopwatch2);
}


void testStopwatch() {
	RUN_TEST(test_StopwatchShouldStart);
	RUN_TEST(test_StopwatchShouldSplit);
	RUN_TEST(test_StopwatchShouldCompare);
	RUN_TEST(test_StopwatchShouldAssign);
}
