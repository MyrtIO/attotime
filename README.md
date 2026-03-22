# Attotime [![Quality Assurance](https://github.com/MyrtIO/attotime/actions/workflows/qa.yaml/badge.svg)](https://github.com/MyrtIO/attotime/actions/workflows/qa.yaml)

Ultra-compact C library for working with timings. Framework-agnostic and overflow-safe.

## Setup

The library requires a clock source — a function that returns current time in
milliseconds as `uint32_t`. Call `atto_init` once at startup:

```c
#include <attotime.h>

// Arduino
void setup() {
    atto_init(millis);
}

// Or any custom clock
uint32_t my_clock(void) { /* ... */ }
atto_init(my_clock);
```

## Usage

### Timer

A simple countdown timer that reports whether a given interval has passed.

```c
atto_timer_t timer = ATTO_TIMER_INIT;

void setup() {
    atto_init(millis);
    atto_timer_start(&timer, 1000);
}

void loop() {
    if (atto_timer_finished(&timer)) {
        // 1 second has passed
    }
}
```

### Stopwatch

Measures how much time has passed since it was started.

```c
atto_stopwatch_t sw = ATTO_STOPWATCH_INIT;

void setup() {
    atto_init(millis);
    atto_stopwatch_start(&sw);
}

void loop() {
    uint32_t elapsed = atto_stopwatch_split(&sw);
}
```

### Progress

Reports the completion of a time interval as a `uint8_t` value (0–255 by
default). Convenient for programming animations.

```c
atto_progress_t progress = ATTO_PROGRESS_INIT;

void setup() {
    atto_init(millis);
    // Ramp from 0 to 255 over 2 seconds
    atto_progress_start(&progress, 2000);
}

void loop() {
    uint8_t brightness = atto_progress_get(&progress);
    // use brightness to drive LEDs, etc.
}
```

## Overflow safety

All time comparisons use elapsed-time arithmetic (`now - start >= duration`)
which handles `uint32_t` wrap-around correctly. Timers, stopwatches and
progress instances keep working across the ~49.7-day `millis()` overflow
boundary.

## Development

Available Makefile targets:

- `test` — Run the unit tests (native).
- `format` — Format C source code.
- `configure` — Initialize the PIO environment.
