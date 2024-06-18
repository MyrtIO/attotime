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
    return millis() >= end_;
  }

  /**
   * Starts the timer with the given duration in milliseconds.
   * @param ms The duration of the timer in milliseconds.
   */
  void start(size_t ms) {
    end_ = millis() + ms;
  }

private:
  uint32_t end_ = 0;
};
