function heapSort(values) {
  const a = [...values ];
  function sift(root, size) {
    while (2 * root + 1 < size) {
      let child = 2 * root + 1;
      if (child + 1 < size && a[child] < a[child + 1])
        child++;
      if (a[root] >= a[child])
        break;
      [a[root], a[child]] = [ a[child], a[root] ];
      root = child;
    }
  }
  for (let i = Math.floor(a.length / 2) - 1; i >= 0; i--)
    sift(i, a.length);
  for (let end = a.length - 1; end > 0; end--) {
    [a[0], a[end]] = [ a[end], a[0] ];
    sift(0, end);
  }
  return a;
}

module.exports = heapSort;
if (require.main === module)
  console.log(heapSort([ 5, 1, 4, 2, 8 ]));
