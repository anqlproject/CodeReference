function insertionSort(values) {
  const a = [...values ];
  for (let i = 1; i < a.length; i++) {
    const value = a[i];
    let j = i - 1;
    while (j >= 0 && a[j] > value) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = value;
  }
  return a;
}

module.exports = insertionSort;
if (require.main === module)
  console.log(insertionSort([ 5, 1, 4, 2, 8 ]));
