package search

func Binary(array []int, target int, lowIndex int, highIndex int) (int, error) {
	if highIndex < lowIndex || len(array) == 0 {
		return -1, ErrNotFound
	}
	mid := int(lowIndex + (highIndex-lowIndex)/2)
	if array[mid] > target {
		return Binary(array, target, lowIndex, mid-1)
	} else if array[mid] < target {
		return Binary(array, target, mid+1, highIndex)
	} else {
		return mid, nil
	}
}

func BinaryIterative(array []int, target int) (int, error) {
	startIndex := 0
	endIndex := len(array) - 1
	var mid int
	for startIndex <= endIndex {
		mid = int(startIndex + (endIndex-startIndex)/2)
		if array[mid] > target {
			endIndex = mid - 1
		} else if array[mid] < target {
			startIndex = mid + 1
		} else {
			return mid, nil
		}
	}
	return -1, ErrNotFound
}

func LowerBound(array []int, target int) (int, error) {
	startIndex := 0
	endIndex := len(array) - 1
	var mid int
	for startIndex <= endIndex {
		mid = int(startIndex + (endIndex-startIndex)/2)
		if array[mid] < target {
			startIndex = mid + 1
		} else {
			endIndex = mid - 1
		}
	}

	if startIndex >= len(array) {
		return -1, ErrNotFound
	}
	return startIndex, nil
}

func UpperBound(array []int, target int) (int, error) {
	startIndex := 0
	endIndex := len(array) - 1
	var mid int
	for startIndex <= endIndex {
		mid = int(startIndex + (endIndex-startIndex)/2)
		if array[mid] > target {
			endIndex = mid - 1
		} else {
			startIndex = mid + 1
		}
	}

	if startIndex >= len(array) {
		return -1, ErrNotFound
	}
	return startIndex, nil
}
