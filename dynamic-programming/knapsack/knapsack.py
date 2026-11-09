def knapsack(weights, values, capacity):
    # 0/1 knapsack; weights and capacity must be nonnegative; returns maximum value.
    if capacity < 0 or any(w < 0 for w in weights):
        raise ValueError("weights and capacity must be nonnegative")
    dp = [0] * (capacity + 1)
    for weight, value in zip(weights, values):
        for c in range(capacity, weight - 1, -1):
            dp[c] = max(dp[c], dp[c - weight] + value)
    return dp[capacity]
if __name__ == "__main__":
    print(knapsack([2, 3, 4], [4, 5, 6], 5))
