function quickSort(values) {
  const a = [...values];
  function partition(lo, hi) { let i = lo, j = hi, pivot = a[Math.floor((lo + hi) / 2)]; while (i <= j) { while (a[i] < pivot) i++; while (a[j] > pivot) j--; if (i <= j) { [a[i], a[j]] = [a[j], a[i]]; i++; j--; } } if (lo < j) partition(lo, j); if (i < hi) partition(i, hi); }
  if (a.length) partition(0, a.length - 1); return a;
}

module.exports = quickSort;
if (require.main === module) console.log(quickSort([5, 1, 4, 2, 8]));
