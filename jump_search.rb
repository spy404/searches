def jump_search(arr, x)
  n = arr.length

  step = Math.sqrt(n)
  prev = 0

  while arr[[step, n].min - 1] < x
    prev = step
    step += Math.sqrt(n)
    return -1 if prev >= n
  end

  while arr[prev] < x
    prev += 1
    return -1 if prev == [step, n].min
  end

  return prev if arr[prev] == x

  -1
end

puts 'Enter a sorted space-separated list:'
arr = gets.chomp.split(' ').map(&:to_i)
puts 'Enter the value to be searched:'
value = gets.chomp.to_i

index = jump_search(arr, value)

puts index == -1 ? 'Element not found' : "Number #{value} is at #{index}"
