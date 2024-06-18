#pragma once

#include <Arduino.h>

/**
 * Represents a timer
 */
class Timer {
public:
  /**
   * Returns true if the timer has finished.
   */
  bool finished() {
    return millis() >= _end;
  }

  /**
   * Starts the timer with the given duration in milliseconds.
   * @param ms The duration of the timer in milliseconds.
   */
  void start(size_t ms) {
    _end = millis() + ms;
  }

private:
  uint32_t _end = 0;
};
