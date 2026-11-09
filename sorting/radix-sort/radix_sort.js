function radixSort(values) {
  let a = [...values ];
  if (a.some(v => v < 0))
    throw new RangeError("radix sort supports non-negative integers only");
  const max = Math.max(0, ...a);
  for (let exp = 1; Math.floor(max / exp) > 0; exp *= 10) {
    const count = Array(10).fill(0), out = Array(a.length);
    for (const v of a)
      count[Math.floor(v / exp) % 10]++;
    for (let i = 1; i < 10; i++)
      count[i] += count[i - 1];
    for (let i = a.length - 1; i >= 0; i--) {
      const d = Math.floor(a[i] / exp) % 10;
      out[--count[d]] = a[i];
    }
    a = out;
  }
  return a;
}

module.exports = radixSort;
if (require.main === module)
  console.log(radixSort([ 5, 1, 4, 2, 8 ]));
