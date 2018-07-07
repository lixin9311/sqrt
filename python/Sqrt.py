#!/usr/bin/env python3
import time
import sys

def eprintf(format, *args):
    sys.stderr.write(format % args)

def new_abs(x):
    if x < 0:
        return -x
    return x

def sqrt(x):
    if x == 0.0:
        return 0.0
    z = 1.0
    for i in range(1, int(x)):
        if new_abs(z * z - x) < 1e-7:
            break
        z -= (z * z - x) / (2.0 * z)
    return z

def main():
    ts1 = time.perf_counter_ns() 
    for i in range(100):
        for j in range(1,501):
            x = sqrt(float(j))
    ts2 = time.perf_counter_ns() 
    wtime = int((ts2 - ts1) / 1000 )
    print("used:", wtime, "ns")
    print("result: ", x)
    eprintf("%d\n", wtime)

if __name__ == "__main__":
    main()

