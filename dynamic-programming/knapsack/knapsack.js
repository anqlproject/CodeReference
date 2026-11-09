function knapsack(
    weights, values,
    capacity) { // 0/1 maximum value; nonnegative weights and capacity.
  if (capacity < 0 || weights.some(w => w < 0))
    throw RangeError("negative weight/capacity");
  const dp = Array(capacity + 1).fill(0);
  for (let i = 0; i < weights.length; i++)
    for (let c = capacity; c >= weights[i]; c--)
      dp[c] = Math.max(dp[c], dp[c - weights[i]] + values[i]);
  return dp[capacity];
}
module.exports = knapsack;
if (require.main === module)
  console.log(knapsack([ 2, 3, 4 ], [ 4, 5, 6 ], 5));
