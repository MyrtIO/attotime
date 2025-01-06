#pragma once

#include <Arduino.h>

/**
 * Progress is a class that reports the progress of a time interval.
 */
class Progress {
public:
	Progress() {}
	~Progress() {}

	Progress& operator =(const Progress& other) {
		start_ = other.start_;
		end_   = other.end_;
		max_   = other.max_;
		return *this;
	}

	bool operator==(const Progress& rhs) {
		return start_ == rhs.start_ && end_ == rhs.end_ && max_ == rhs.max_;
	}
	bool operator!=(const Progress& rhs) {
		return start_ != rhs.start_ || end_ != rhs.end_ || max_ != rhs.max_;
	}

	/**
	 * Returns true if the progress timer has been started.
	 */
	bool started() {
		return start_ != 0;
	}

	/**
	 * Returns true if the progress timer has finished.
	 */
	bool finished() {
		return started() && millis() >= end_;
	}

	/**
	 * Returns the current progress as a value between 0 and max_.
	 */
	inline uint8_t get() {
		if (!started()) {
			return 0;
		}
    	uint32_t now = millis();
		if (now >= end_) {
			return max_;
		}
		return map(now, start_, end_, 0, max_);
	}

	/**
	 * Starts a progress timer with the given duration in milliseconds.
	 * @param ms The duration of the progress timer in milliseconds.
	 */
	inline void start(size_t ms) {
		start_ = millis();
		end_   = start_ + ms;
	}

	/**
	 * Sets the maximum value of the progress timer.
	 * @param max The maximum value of the progress timer.
	 */
	void setMax(const uint8_t max) {
		max_ = max;
	}

	/**
	 * Resets the progress timer.
	 */
	void reset() {
		start_ = 0;
		end_   = 0;
	}

private:
	uint32_t start_ = 0;
	uint32_t end_   = 0;
	uint8_t max_    = 255;
};
