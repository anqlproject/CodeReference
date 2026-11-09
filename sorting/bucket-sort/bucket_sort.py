from __future__ import annotations


def bucket_sort(values: list[int]) -> list[int]:
    a = list(values)
    if len(a) < 2:
        return a
    low, high = min(a), max(a)
    if low == high:
        return a
    buckets = [[] for _ in range(len(a))]
    span = high - low + 1
    for value in a:
        index = min((value - low) * len(buckets) // span, len(buckets) - 1)
        buckets[index].append(value)
    result = []
    for bucket in buckets:
        for i in range(1, len(bucket)):
            value, j = bucket[i], i - 1
            while j >= 0 and bucket[j] > value:
                bucket[j + 1] = bucket[j]
                j -= 1
            bucket[j + 1] = value
        result.extend(bucket)
    return result


if __name__ == "__main__":
    print(bucket_sort([5, 1, 4, 2, 8]))
