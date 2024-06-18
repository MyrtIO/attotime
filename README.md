# ⏰ Attotime [![Quality Assurance](https://github.com/MyrtIO/attotime/actions/workflows/qa.yaml/badge.svg)](https://github.com/MyrtIO/attotime/actions/workflows/qa.yaml)

Ultra-compact library for working with timings on Arduino (or other boards with Arduino framework).

## Usage

### Timer

Timer is the simplest class that allows you to set a time interval and determine if it has passed.

```cpp
#include <attotime.h>

Timer timer;

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
#include <attotime.h>

Stopwatch stopwatch;

void setup() {
  Serial.begin(115200);
  stopwatch.start();
}

void loop() {
  Serial.printf("Stopwatch time: %d\n", stopwatch.split());
}
