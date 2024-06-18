# PicoTime

Ultra-compact library for working with timings on Arduino (or other boards with Arduino framework).

## Usage

### Timer

Timer is the simplest class that allows you to set a time interval and determine if it has passed.

```cpp
#include <PicoTime.h>

PicoTime timer;

void setup() {
  Serial.begin(115200);
  timer.start(1000);
}

void loop() {
  if (timer.isExpired()) {
    Serial.println("Timer expired!");
  }
}
```

### Stopwatch

Stopwatch allows you to measure how much time has passed since it was started.

```cpp
#include <PicoTime.h>

PicoTime stopwatch;

void setup() {
  Serial.begin(115200);
  stopwatch.start();
}

void loop() {
  Serial.printf("Stopwatch time: %d\n", stopwatch.split());
}
