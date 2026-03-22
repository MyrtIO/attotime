#include "attotime.h"

static atto_clock_fn atto_clock = 0;

void atto_init(atto_clock_fn clock) { atto_clock = clock; }

uint32_t atto_now(void) { return atto_clock(); }

/* ── Timer ─────────────────────────────────────────────────────────── */

void atto_timer_start(atto_timer_t *t, uint32_t ms) {
  t->start = atto_now();
  t->duration = ms;
}

void atto_timer_reset(atto_timer_t *t) {
  t->start = 0;
  t->duration = 0;
}

bool atto_timer_started(const atto_timer_t *t) { return t->duration > 0; }

bool atto_timer_finished(const atto_timer_t *t) {
  if (t->duration == 0) {
    return false;
  }
  return (atto_now() - t->start) >= t->duration;
}

/* ── Stopwatch ─────────────────────────────────────────────────────── */

void atto_stopwatch_start(atto_stopwatch_t *sw) {
  sw->started = true;
  sw->start = atto_now();
}

void atto_stopwatch_reset(atto_stopwatch_t *sw) {
  sw->started = false;
  sw->start = 0;
}

bool atto_stopwatch_started(const atto_stopwatch_t *sw) { return sw->started; }

uint32_t atto_stopwatch_split(const atto_stopwatch_t *sw) {
  if (!sw->started) {
    return 0;
  }
  return atto_now() - sw->start;
}

/* ── Progress ──────────────────────────────────────────────────────── */

void atto_progress_start(atto_progress_t *p, uint32_t ms) {
  p->start = atto_now();
  p->duration = ms;
}

void atto_progress_reset(atto_progress_t *p) {
  p->start = 0;
  p->duration = 0;
}

void atto_progress_set_max(atto_progress_t *p, uint8_t max) { p->max = max; }

bool atto_progress_started(const atto_progress_t *p) { return p->duration > 0; }

bool atto_progress_finished(const atto_progress_t *p) {
  if (p->duration == 0) {
    return false;
  }
  return (atto_now() - p->start) >= p->duration;
}

uint8_t atto_progress_get(const atto_progress_t *p) {
  if (p->duration == 0) {
    return 0;
  }
  uint32_t elapsed = atto_now() - p->start;
  if (elapsed >= p->duration) {
    return p->max;
  }
  return (uint8_t)((uint64_t)elapsed * p->max / p->duration);
}
