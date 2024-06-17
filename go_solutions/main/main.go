package main

import (
	"fmt"
	"math"
)

func miniMaxSum(arr []int32) {
	mx, mn, sum := int64(0), int64(math.MaxInt32), int64(0)

	for _, v := range arr {
		sum += int64(v)

		if int64(v) > mx {
			mx = int64(v)
		}

		if int64(v) < mn {
			mn = int64(v)
		}

	}

	fmt.Printf("%d %d", sum-mx, sum-mn)
}

func plusMinus(arr []int32) {
	ps, ng, zr := int32(0), int32(0), int32(0)

	for _, v := range arr {
		if v > 0 {
			ps++
		} else if v < 0 {
			ng++
		} else {
			zr++
		}
	}
	length := len(arr)

	fmt.Printf("%.6f\n", float64(ps)/float64(length))
	fmt.Printf("%.6f\n", float64(ng)/float64(length))
	fmt.Printf("%.6f\n", float64(zr)/float64(length))

}

func diagonalDifference(arr [][]int32) int32 {
	lr, rl := int32(0), int32(0)

	for i, length := 0, len(arr); i < length; i++ {
		lr += arr[i][i]
		rl += arr[i][length-i-1]
	}

	diff := lr - rl

	if diff < 0 {
		diff *= -1
	}

	return diff
}

func aVeryBigSum(ar []int64) int64 {
	sum := int64(0)

	for _, e := range ar {
		sum += e
	}
	return sum

}

func compareTriplets(a []int32, b []int32) []int32 {
	res := []int32{0, 0}

	for i, aEl := range a {
		if aEl > b[i] {
			res[0]++
		} else if aEl < b[i] {
			res[1]++
		}
	}

	return res
}

func simpleArraySum(ar []int32) int32 {
	sum := int32(0)

	for _, e := range ar {
		sum += e
	}

	return sum
}

func main() {
	staircase(4)
}
