def interpolation_search(values, target):
    # Input must be sorted ascending; return any matching duplicate index.
    lo, hi = 0, len(values) - 1
    while lo <= hi and values[lo] <= target <= values[hi]:
        if values[lo] == values[hi]:
            return lo if values[lo] == target else -1
        pos = lo + (target - values[lo]) * (hi - lo) // (values[hi] - values[lo])
        if values[pos] == target:
            return pos
        if values[pos] < target:
            lo = pos + 1
        else: hi = pos - 1
    return -1
if __name__ == "__main__":
    print(interpolation_search([1, 2, 2, 4, 8], 2))
