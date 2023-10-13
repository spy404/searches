export const fibonacciSearch = (arr, x, n) => {
  let fib2 = 0
  let fib1 = 1
  let fibK = fib2 + fib1

  while (fibK < n) {
    fib2 = fib1
    fib1 = fibK
    fibK = fib2 + fib1
  }
  let offset = -1

  while (fibK > 1) {
    const i = Math.min(offset + fib2, n - 1)

    if (arr[i] < x) {
      fibK = fib1
      fib1 = fib2
      fib2 = fibK - fib1
      offset = i
    } else if (arr[i] > x) {
      fibK = fib2
      fib1 = fib1 - fib2
      fib2 = fibK - fib1
    } else {
      return i
    }
  }

  if (fib1 && arr[offset + 1] === x) {
    return offset + 1
  }
  return -1
}
