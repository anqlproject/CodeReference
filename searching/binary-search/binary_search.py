def binary_search(values, target):
    lo, hi = 0, len(values) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if values[mid] == target:
            return mid
        if values[mid] < target:
            lo = mid + 1
        else: hi = mid - 1
    return -1
if __name__ == "__main__":
    print(binary_search([1, 3, 5, 7], 5))
