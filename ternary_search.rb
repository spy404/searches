def ternary_search(l, r, key, arr)
  if r >= l
      mid1 = l + (r - l) / 3
      mid2 = r - (r - l) / 3
      if arr[mid1] == key
          mid1
      elsif arr[mid2] == key
          mid2
      elsif key < arr[mid1]
          ternary_search(l, mid1 - 1, key, arr)
      elsif key > arr[mid2]
          ternary_search(mid2 + 1, r, key, arr)
      else
          ternary_search(mid1 + 1, mid2 - 1, key, arr)
      end
  end
end

puts "Enter a space-separated list:"
arr = gets.chomp.split(' ').map(&:to_i)
puts "Enter a value to be searched:"
key = gets.chomp.to_i
puts if ternary_search(0, arr.length - 1, key, arr) != nil
  "Found at index #{ternary_search(0, arr.length - 1, key, arr)}"
else
  "Not found"
end
