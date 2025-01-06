#pragma once

#include <Arduino.h>

/**
 * Stopwatch is a class that allows you to measure the elapsed time.
 */
class Stopwatch {
public:
	Stopwatch() {}
	~Stopwatch() {}

	Stopwatch& operator =(const Stopwatch& other) {
		started_ = other.started_;
		start_   = other.start_;
		return *this;
	}

	bool operator==(const Stopwatch& rhs) {
		return
			started_ == rhs.started_ &&
			start_   == rhs.start_;
	}
	bool operator!=(const Stopwatch& rhs) {
		return
			started_ != rhs.started_ ||
			start_   != rhs.start_;
	}

	/**
	 * Starts the timer
	 */
	void start() {
		started_ = true;
		start_   = millis();
	}

	void reset() {
		started_ = false;
		start_   = 0;
	}

	/**
	 * Returns the elapsed time in milliseconds
	 */
	uint32_t split() {
		if (!started_) {
			return 0;
		}
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
