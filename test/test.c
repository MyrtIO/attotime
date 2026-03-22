#include "test.h"
#include <attotime.h>
#include <unity.h>

uint32_t mock_time = 0;

static uint32_t mock_clock(void) { return mock_time; }

void setUp(void) { mock_time = 0; }

void tearDown(void) {}

int main(void) {
  atto_init(mock_clock);
  UNITY_BEGIN();
  testTimer();
  testStopwatch();
  testProgress();
  return UNITY_END();
}
