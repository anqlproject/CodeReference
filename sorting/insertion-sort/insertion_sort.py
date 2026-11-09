from __future__ import annotations


def insertion_sort(values: list[int]) -> list[int]:
    a = list(values)
    for i in range(1, len(a)):
        value = a[i]
        j = i - 1
        while j >= 0 and a[j] > value:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = value
    return a


if __name__ == "__main__":
    print(insertion_sort([5, 1, 4, 2, 8]))
