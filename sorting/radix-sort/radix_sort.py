from __future__ import annotations


def radix_sort(values: list[int]) -> list[int]:
    a = list(values)
    if any(value < 0 for value in a):
        raise ValueError("radix_sort supports non-negative integers only")
    exp, maximum = 1, max(a, default=0)
    while maximum // exp > 0:
        counts = [0] * 10
        output = [0] * len(a)
        for value in a:
            counts[(value // exp) % 10] += 1
        for i in range(1, 10):
            counts[i] += counts[i - 1]
        for value in reversed(a):
            digit = (value // exp) % 10
            counts[digit] -= 1
            output[counts[digit]] = value
        a = output
        exp *= 10
    return a


if __name__ == "__main__":
    print(radix_sort([5, 1, 4, 2, 8]))
