export function quickSelectSearch(array, k) {
  if (!array || array.length <= k) {
    throw new Error('Invalid arguments')
  }

  let from = 0
  let to = array.length - 1
  while (from < to) {
    let left = from
    let right = to
    const pivot = array[Math.ceil((left + right) * 0.5)]

    while (left < right) {
      if (array[left] >= pivot) {
        const tmp = array[left]
        array[left] = array[right]
        array[right] = tmp
        --right
      } else {
        ++left
      }
    }

    if (array[left] > pivot) {
      --left
    }

    if (k <= left) {
      to = left
    } else {
      from = left + 1
    }
  }
  return array
}
