#include "stdio.h"
// #include "math.h"
#include "timing.h"

static inline double new_fabs(double x) {
  if (x < 0) return -x;
  return x;
}

static inline double new_sqrt(double x) {
  if (x == 0.0) return 0.0;
  double z = 1.0;
  for (int i = 0; i < (int)x; i++) {
    if (new_fabs(z * z - x) < 1e-7) break;
    z -= (z * z - x) / (2.0 * z);
  }
  return z;
}

int main(int argc, char const *argv[]) {
  /* code */
  uint64 ts1, ts2, wtime;
  int i, j;
  double x;
  asm volatile("# START!!!");
  ts1 = rdtscp();
  for (i = 0; i < 100; i++) {
   for (j = 1; j < 501; j++) {
      x = new_sqrt((double)j);
   }
  }
  asm volatile("# END!!!");
  ts2 = rdtscp();
  wtime = tickToUsec(ts1, ts2);
  printf("used: %llu us\n", wtime);
  printf("result: %lf\n", x);
  fprintf(stderr, "%llu\n", wtime);
  return 0;
}
