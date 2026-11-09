function selectionSort(values) {
  const a = [...values];
  for (let i = 0; i < a.length; i++) { let min = i; for (let j = i + 1; j < a.length; j++) if (a[j] < a[min]) min = j; [a[i], a[min]] = [a[min], a[i]]; }
  return a;
}

module.exports = selectionSort;
if (require.main === module) console.log(selectionSort([5, 1, 4, 2, 8]));
