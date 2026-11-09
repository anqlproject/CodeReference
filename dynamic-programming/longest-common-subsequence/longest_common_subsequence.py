def longest_common_subsequence(a, b):
    # Returns the length of a longest common subsequence.
    dp = [0] * (len(b) + 1)
    for x in a:
        previous = 0
        for j, y in enumerate(b, 1):
            old = dp[j]
            dp[j] = previous + 1 if x == y else max(dp[j], dp[j - 1])
            previous = old
    return dp[-1]
if __name__ == "__main__":
    print(longest_common_subsequence("ABCBDAB", "BDCAB"))
