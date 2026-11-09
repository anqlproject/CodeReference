function shellSort(values) {
  const a = [...values ];
  for (let gap = Math.floor(a.length / 2); gap > 0; gap = Math.floor(gap / 2))
    for (let i = gap; i < a.length; i++) {
      const v = a[i];
      let j = i;
      while (j >= gap && a[j - gap] > v) {
        a[j] = a[j - gap];
        j -= gap;
      }
      a[j] = v;
    }
  return a;
}

module.exports = shellSort;
if (require.main === module)
  console.log(shellSort([ 5, 1, 4, 2, 8 ]));
