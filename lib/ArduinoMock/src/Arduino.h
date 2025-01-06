#pragma once

#include <stdio.h>
#include <time.h>
#include <unistd.h>

#ifndef ARDUINO
#define ARDUINO 1

// Function to pause the program execution for a specified number of milliseconds
inline void delay(unsigned long ms) {
  usleep(ms * 1000); // Convert milliseconds to microseconds
}

// Function to return the number of milliseconds since the program started
inline unsigned long millis() {
  struct timespec spec;
  clock_gettime(CLOCK_MONOTONIC, &spec);
  return (spec.tv_sec * 1000) + (spec.tv_nsec / 1e6);
}

inline long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

#endif
