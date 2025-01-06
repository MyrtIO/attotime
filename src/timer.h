#pragma once

#include <Arduino.h>

/**
 * Timer is a class that allows you to set a time interval and determine if it has passed.
 */
class Timer {
public:
	Timer() {}
	~Timer() {}

	Timer& operator =(const Timer& other) {
		end_ = other.end_;
		return *this;
	}

	bool operator==(const Timer& rhs) {
		return end_ == rhs.end_;
	}
	bool operator!=(const Timer& rhs) {
		return end_ != rhs.end_;
	}

	/**
	 * Returns true if the timer has finished.
	 */
	bool finished() {
		return millis() >= end_;
	}

	/**
	 * Returns true if the timer has been started.
	 */
	bool started() {
		return end_ != 0;
	}

	/**
	 * Resets the timer.
	 */
	void reset() {
		end_ = 0;
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
