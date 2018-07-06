#include "stdio.h"
#include "math.h"
#include "timing.h"

static inline double new_sqrt(double x) {
  if (x == 0.0) return 0.0;
  double z = 1.0;
  for (int i = 0; i < (int)x; i++) {
    if (fabs(z * z - x) < 1e-7) break;
    z -= (z * z - x) / (2.0 * x);
  }
  return z;
}

int main(int argc, char const *argv[]) {
  /* code */
  uint64 ts1, ts2, wtime;
  ts1 = rdtscp();
  int i, j;
  double x;
  for (i = 0; i < 100; i++) {
    for (j = 1; j < 501; j++) {
      x = new_sqrt((double)j);
    }
  }
  ts2 = rdtscp();
  wtime = tickToUsec(ts1, ts2);
  printf("used: %llu us\n", wtime);
  printf("result: %lf\n", x);
  return 0;
}
