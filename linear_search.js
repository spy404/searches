function SearchArray(searchNum, ar, output = (v) => console.log(v)) {
  const position = Search(ar, searchNum)
  if (position !== -1) {
    output('The element was found at ' + (position + 1))
  } else {
    output('The element not found')
  }
}

function Search(theArray, key) {
  for (let n = 0; n < theArray.length; n++) {
    if (theArray[n] === key) {
      return n
    }
  }
  return -1
}

export { SearchArray, Search }
