function bubbleSort(values) {
  const a = [...values];
  for (let end = a.length - 1; end > 0; end--) { let swapped = false; for (let i = 0; i < end; i++) if (a[i] > a[i + 1]) { [a[i], a[i + 1]] = [a[i + 1], a[i]]; swapped = true; } if (!swapped) break; }
  return a;
}

module.exports = bubbleSort;
if (require.main === module) console.log(bubbleSort([5, 1, 4, 2, 8]));
