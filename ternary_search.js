function ternarySearchRecursive(arr, key, low = 0, high = arr.length - 1) {
  if (high >= low) {
    const mid1 = Math.floor(low + (high - low) / 3)
    const mid2 = Math.floor(high - (high - low) / 3)

    if (arr[mid1] === key) {
      return mid1
    }
    if (arr[mid2] === key) {
      return mid2
    }

    if (key < arr[mid1]) {
      return ternarySearchRecursive(arr, key, low, mid1 - 1)
    } else if (key > arr[mid2]) {
      return ternarySearchRecursive(arr, key, mid2 + 1, high)
    } else {
      return ternarySearchRecursive(arr, key, mid1 + 1, mid2 - 1)
    }
  } else {
    return -1
  }
}

function ternarySearchIterative(arr, key, low = 0, high = arr.length - 1) {
  while (high >= low) {
    const mid1 = Math.floor(low + (high - low) / 3)
    const mid2 = Math.floor(high - (high - low) / 3)

    if (arr[mid1] === key) {
      return mid1
    }
    if (arr[mid2] === key) {
      return mid2
    }

    if (key < arr[mid1]) {
      high = mid1 - 1
    } else if (key > arr[mid2]) {
      low = mid2 + 1
    } else {
      low = mid1 + 1
      high = mid2 - 1
    }
  }
  return -1
}

export { ternarySearchRecursive, ternarySearchIterative }
