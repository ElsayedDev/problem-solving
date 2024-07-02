package main

import (
	"fmt"
	"math"
)

type pair struct {
	val, counter int
}

func equalFrequency(word string) bool {
	freq := make(map[rune]int)

	for _, w := range word {
		freq[w]++
	}

	setFreq := make(map[int]pair)

	for _, f := range freq {
		if _, ok := setFreq[f]; !ok {

			setFreq[f] = pair{f, 1}

		} else {
			setFreq[f] = pair{f, setFreq[f].counter + 1}

		}

	}
	if len(setFreq) == 1 {
		for _, v := range setFreq {
			if v.val == 1 || v.counter == 1 {
				return true
			}
		}

		return false

	}

	if len(setFreq) > 2 {
		return false
	}
	var val1, val2 int

	for _, v := range setFreq {
		if val1 == 0 {
			val1 = v.val
		} else {
			val2 = v.val
		}
	}

	diff := int(math.Abs(float64(val1 - val2)))

	if diff == 1 {
		return true
	}

	return false
}

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
	fmt.Println(equalFrequency("ddaccb"))
	fmt.Println(equalFrequency("dca"))
}
