package search

import "math"

func Jump(array []int, target int) (int, error) {
	n := len(array)
	if n == 0 {
		return -1, ErrNotFound
	}

  step := int(math.Round(math.Sqrt(float64(n))))

	prev := 0
	curr := step
	for array[curr-1] < target {
		prev = curr
		if prev >= len(array) {
			return -1, ErrNotFound
		}

		curr += step

		if curr > n {
			curr = n
		}
	}

	for array[prev] < target {
		prev++

		if prev == curr {
			return -1, ErrNotFound
		}
	}
	if array[prev] == target {
		return prev, nil
	}

	return -1, ErrNotFound

}
