function binarySearch(a, x) {
  let l = 0, r = a.length - 1;
  while (l <= r) {
    let m = Math.floor((l + r) / 2);
    if (a[m] === x)
      return m;
    if (a[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
module.exports = binarySearch;
if (require.main === module)
  console.log(binarySearch([ 1, 3, 5, 7 ], 5));
