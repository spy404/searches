package search

func Interpolation(sortedData []int, guess int) (int, error) {
	if len(sortedData) == 0 {
		return -1, ErrNotFound
	}

	var (
		low, high       = 0, len(sortedData) - 1
		lowVal, highVal = sortedData[low], sortedData[high]
	)

	for lowVal != highVal && (lowVal <= guess) && (guess <= highVal) {
		mid := low + int(float64(float64((guess-lowVal)*(high-low))/float64(highVal-lowVal)))

		if sortedData[mid] == guess {
			for mid > 0 && sortedData[mid-1] == guess {
				mid--
			}
			return mid, nil

		}

		if sortedData[mid] > guess {
			high, highVal = mid-1, sortedData[high]

		} else {
			low, lowVal = mid+1, sortedData[low]
		}

	}

	if guess == lowVal {
		return low, nil
	}
	return -1, ErrNotFound
}
