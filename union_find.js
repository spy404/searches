function UnionFind(n, key) {
  if (!(this instanceof UnionFind)) return new UnionFind(n)
  if (key && typeof key !== 'function') {
    throw new Error('key has to be a function or else left undefined')
  }
  let cnt, length
  key =
    key ||
    function (a) {
      return a
    }
  cnt = length = n
  const id = new Array(n)
  const sz = new Array(n)
  for (let i = 0; i < n; i++) {
    id[i] = i
    sz[i] = 1
  }
  this.size = function () {
    return length
  }
  this.count = function () {
    return cnt
  }
  this.find = function (p) {
    p = key(p)
    while (p !== id[p]) {
      id[p] = id[id[p]]
      p = id[p]
    }
    return p
  }
  this.connected = function (p, q) {
    p = key(p)
    q = key(q)
    ensureIndexWithinBounds(p, q)
    return this.find(p) === this.find(q)
  }
  this.union = function (p, q) {
    p = key(p)
    q = key(q)
    ensureIndexWithinBounds(p, q)
    const i = this.find(p)
    const j = this.find(q)
    if (i === j) return
    if (sz[i] < sz[j]) {
      id[i] = j
      sz[j] += sz[i]
    } else {
      id[j] = i
      sz[i] += sz[j]
    }
    cnt--
  }
  function ensureIndexWithinBounds(args) {
    for (let i = arguments.length - 1; i >= 0; i--) {
      const p = arguments[i]
      if (p >= length)
        throw new Error(
          'Index out of bounds. The maximum index can be length-1'
        )
    }
  }
}

export { UnionFind }
