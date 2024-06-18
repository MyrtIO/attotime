#pragma once

#include <Arduino.h>

/**
 * Represents a progress timer.
 */
class Progress {
public:
  /**
   * Returns the current progress as a value between 0 and max_.
   */
  uint8_t get() {
    now_ = millis();
    if (now_ >= end_) {
      return max_;
    }
    return map(now_, start_, end_, 0, max_);
  }

  /**
   * Starts a progress timer with the given duration in milliseconds.
   * @param ms The duration of the progress timer in milliseconds.
   */
  void start(size_t ms) {
    start_ = millis();
    end_   = start_ + ms;
  }

  /**
   * Sets the maximum value of the progress timer.
   * @param max The maximum value of the progress timer.
   */
  void setMax(uint8_t max) {
    max_ = max;
  }

  /**
   * Returns true if the progress timer has finished.
   */
  bool finished() {
    return millis() >= end_;
  }

private:
  uint32_t start_ = 0;
  uint32_t end_   = 0;
  uint32_t now_   = 0;
  uint8_t max_    = 255;
};
