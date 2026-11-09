function interpolationSearch(a, x) { // Ascending integers; any duplicate match.
  let l = 0, r = a.length - 1;
  while (l <= r && a[l] <= x && x <= a[r]) {
    if (a[l] === a[r])
      return a[l] === x ? l : -1;
    const p = l + Math.floor((x - a[l]) * (r - l) / (a[r] - a[l]));
    if (a[p] === x)
      return p;
    if (a[p] < x)
      l = p + 1;
    else
      r = p - 1;
  }
  return -1;
}
module.exports = interpolationSearch;
if (require.main === module)
  console.log(interpolationSearch([ 1, 2, 2, 4 ], 2));
