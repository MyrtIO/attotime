#include <unity.h>
#include <Arduino.h>
#include <Attotime.h>

void test_TimerShouldReportFinish() {
	Timer timer;
	timer.start(10);
	TEST_ASSERT_FALSE(timer.finished());
	delay(10);
	TEST_ASSERT_TRUE(timer.finished());
}

void test_TimerShouldCopy() {
    Timer timer1;
    timer1.start(10);
    Timer timer2;
    timer2 = timer1;
    TEST_ASSERT_FALSE(timer2.finished());
    delay(10);
    TEST_ASSERT_TRUE(timer2.finished());
}

void test_TimerShouldCompare() {
    Timer timer1;
    Timer timer2;
    TEST_ASSERT_TRUE(timer1 == timer2);
    timer1.start(10);
    TEST_ASSERT_FALSE(timer1 == timer2);
    TEST_ASSERT_TRUE(timer1 != timer2);
    timer2.start(10);
    TEST_ASSERT_TRUE(timer1 == timer2);
}

void test_TimerShouldAssign() {
	Stopwatch timer1;
    Stopwatch timer2;
    timer1.start();
    delay(5);
    timer2 = timer1;
    TEST_ASSERT_TRUE(timer2.started());
    TEST_ASSERT_EQUAL_UINT32(timer1.split(), timer2.split());
	TEST_ASSERT_TRUE(timer1 == timer2);
	TEST_ASSERT_FALSE(timer1 != timer2);
}

void testTimer() {
	RUN_TEST(test_TimerShouldReportFinish);
	RUN_TEST(test_TimerShouldCopy);
	RUN_TEST(test_TimerShouldCompare);
	RUN_TEST(test_TimerShouldAssign);
}
