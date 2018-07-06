package main

import (
	"fmt"
	"math"
	"time"
)

func sqrt(x float64) float64 {
	if x == 0.0 {
		return 0.0
	}
	z := 1.0
	for i := 0; i < int(x); i++ {
		if math.Abs(z*z-x) < 1e-7 {
			break
		}
		z -= (z*z - x) / (2.0 * z)
	}
	return z
}

func main() {
	ts1 := time.Now()
	var x float64
	for i := 0; i < 100; i++ {
		for n := 1; n < 501; n++ {
			x = sqrt(float64(n))
		}
	}
	ts2 := time.Now()
	dura := ts2.Sub(ts1)
	fmt.Printf("used: %d us\n", int64(dura/time.Microsecond))
	fmt.Println("result: ", x)
}
