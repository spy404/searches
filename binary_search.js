function binarySearchRecursive(arr, x, low = 0, high = arr.length - 1) {
  const mid = Math.floor(low + (high - low) / 2)

  if (high >= low) {
    if (arr[mid] === x) {
      return mid
    }

    if (x < arr[mid]) {
      return binarySearchRecursive(arr, x, low, mid - 1)
    } else {
      return binarySearchRecursive(arr, x, mid + 1, high)
    }
  } else {
    return -1
  }
}
function binarySearchIterative(arr, x, low = 0, high = arr.length - 1) {
  while (high >= low) {
    const mid = Math.floor(low + (high - low) / 2)

    if (arr[mid] === x) {
      return mid
    }

    if (x < arr[mid]) {
      high = mid - 1
    } else {
      low = mid + 1
    }
  }
  return -1
}

export { binarySearchIterative, binarySearchRecursive }
