#!/usr/bin/env python3
import time

def sqrt(x):
    if x == 0.0:
        return 0.0
    z = 1.0
    for i in range(1, int(x)):
        if abs(z * z - x) < 1e-7:
            break
        z -= (z * z - x) / (2.0 * x)
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

if __name__ == "__main__":
    main()

