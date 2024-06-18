#pragma once

#include <Arduino.h>

/**
 * Represents a stopwatch
 */
class Stopwatch {
public:
  /**
   * Starts the timer
   */
  void start() {
    started_ = true;
    start_   = millis();
  }

  /**
   * Returns the elapsed time in milliseconds
   */
  uint32_t split() {
    return millis() - start_;
  }

  /**
   * Returns true if the timer has been started
   */
  bool started() {
    return started_;
  }

private:
  uint32_t start_ = 0;
  bool started_   = false;
};
