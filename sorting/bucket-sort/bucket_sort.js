function bucketSort(values) {
  if (values.length < 2) return [...values]; const min = Math.min(...values), max = Math.max(...values); if (min === max) return [...values]; const buckets = Array.from({ length: values.length }, () => []), span = max - min + 1; for (const v of values) buckets[Math.min(Math.floor((v - min) * buckets.length / span), buckets.length - 1)].push(v); const result = []; for (const bucket of buckets) { for (let i = 1; i < bucket.length; i++) { const v = bucket[i]; let j = i - 1; while (j >= 0 && bucket[j] > v) { bucket[j + 1] = bucket[j]; j--; } bucket[j + 1] = v; } result.push(...bucket); } return result;
}

module.exports = bucketSort;
if (require.main === module) console.log(bucketSort([5, 1, 4, 2, 8]));
