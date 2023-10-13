export function interpolationSearch(arr, key) {
  const length = arr.length - 1
  let low = 0
  let high = length
  let position = -1
  let delta = -1

  while (low <= high && key >= arr[low] && key <= arr[high]) {
    delta = (key - arr[low]) / (arr[high] - arr[low])
    position = low + Math.floor((high - low) * delta)

    if (arr[position] === key) {
      return position
    }

    if (arr[position] < key) {
      low = position + 1
    } else {
      high = position - 1
    }
  }

  return -1
}
