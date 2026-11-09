from __future__ import annotations


def counting_sort(values: list[int]) -> list[int]:
    # The integer range must be small enough for its count array to fit in memory.
    a = list(values)
    if not a: return a
    low, high = min(a), max(a)
    counts = [0] * (high - low + 1)
    for value in a: counts[value - low] += 1
    return [value + low for offset, count in enumerate(counts) for value in [offset] * count]


if __name__ == "__main__":
    print(counting_sort([5, 1, 4, 2, 8]))
