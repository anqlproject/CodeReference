function countingSort(values) {
  // The integer range must be small enough for its count array to fit in
  // memory.
  if (!values.length)
    return [];
  const min = Math.min(...values), max = Math.max(...values);
  const counts = Array(max - min + 1).fill(0);
  for (const v of values)
    counts[v - min]++;
  const result = [];
  for (let i = 0; i < counts.length; i++)
    for (let n = counts[i]; n > 0; n--)
      result.push(i + min);
  return result;
}

module.exports = countingSort;
if (require.main === module)
  console.log(countingSort([ 5, 1, 4, 2, 8 ]));
