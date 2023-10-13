def linear_search(array, key)
  array.each_with_index do |current, index|
    return index if current == key
  end
  nil
end

puts "Enter a space-separated list:"
arr = gets.chomp.split(' ').map(&:to_i)
puts "Enter a value to be searched:"
key = gets.chomp.to_i
puts if linear_search(arr, key) != nil
  "Found at index #{linear_search(arr, key)}"
else
  "Not found"
end
