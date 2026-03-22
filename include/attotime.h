#pragma once

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Clock function type: returns current time in milliseconds. */
typedef uint32_t (*atto_clock_fn)(void);

/**
 * Initializes the library with a clock source.
 * Must be called before using any other atto_* function.
 */
void atto_init(atto_clock_fn clock);

/** Returns the current time via the registered clock. */
uint32_t atto_now(void);

/* ── Timer ─────────────────────────────────────────────────────────── */

typedef struct {
  uint32_t start;
  uint32_t duration;
} atto_timer_t;

#define ATTO_TIMER_INIT {0, 0}

void atto_timer_start(atto_timer_t *t, uint32_t ms);
void atto_timer_reset(atto_timer_t *t);
bool atto_timer_started(const atto_timer_t *t);
bool atto_timer_finished(const atto_timer_t *t);

/* ── Stopwatch ─────────────────────────────────────────────────────── */

typedef struct {
  uint32_t start;
  bool started;
} atto_stopwatch_t;

#define ATTO_STOPWATCH_INIT {0, false}

void atto_stopwatch_start(atto_stopwatch_t *sw);
void atto_stopwatch_reset(atto_stopwatch_t *sw);
bool atto_stopwatch_started(const atto_stopwatch_t *sw);
uint32_t atto_stopwatch_split(const atto_stopwatch_t *sw);

/* ── Progress ──────────────────────────────────────────────────────── */

typedef struct {
  uint32_t start;
  uint32_t duration;
  uint8_t max;
} atto_progress_t;

#define ATTO_PROGRESS_INIT {0, 0, 255}

void atto_progress_start(atto_progress_t *p, uint32_t ms);
void atto_progress_reset(atto_progress_t *p);
void atto_progress_set_max(atto_progress_t *p, uint8_t max);
bool atto_progress_started(const atto_progress_t *p);
bool atto_progress_finished(const atto_progress_t *p);
uint8_t atto_progress_get(const atto_progress_t *p);

#ifdef __cplusplus
}
#endif
