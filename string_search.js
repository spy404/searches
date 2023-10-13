function makeTable(str) {
  const table = new Array(str.length)
  let maxPrefix = 0
  table[0] = 0

  for (let i = 1; i < str.length; i++) {
    while (maxPrefix > 0 && str.charAt(i) !== str.charAt(maxPrefix)) {
      maxPrefix = table[maxPrefix - 1]
    }
    if (str.charAt(maxPrefix) === str.charAt(i)) {
      maxPrefix++
    }
    table[i] = maxPrefix
  }
  return table
}

export function stringSearch(str, word) {
  const prefixes = makeTable(word)
  const matches = []

  let j = 0
  let i = 0
  while (i < str.length) {
    if (str.charAt(i) === word.charAt(j)) {
      i++
      j++
    }
    if (j === word.length) {
      matches.push(i - j)
      j = prefixes[j - 1]
    } else if (str.charAt(i) !== word.charAt(j)) {
      if (j !== 0) {
        j = prefixes[j - 1]
      } else {
        i++
      }
    }
  }

  return matches
}
