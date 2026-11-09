function mergeSort(values) {
  const a = [...values];
  function split(lo, hi) { if (hi - lo < 2) return; const mid = Math.floor((lo + hi) / 2); split(lo, mid); split(mid, hi); const left = a.slice(lo, mid), right = a.slice(mid, hi); let i = 0, j = 0; for (let k = lo; k < hi; k++) a[k] = j === right.length || (i < left.length && left[i] <= right[j]) ? left[i++] : right[j++]; }
  split(0, a.length); return a;
}

module.exports = mergeSort;
if (require.main === module) console.log(mergeSort([5, 1, 4, 2, 8]));
