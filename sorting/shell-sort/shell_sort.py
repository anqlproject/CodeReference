from __future__ import annotations


def shell_sort(values: list[int]) -> list[int]:
    a = list(values)
    gap = len(a) // 2
    while gap > 0:
        for i in range(gap, len(a)):
            value, j = a[i], i
            while j >= gap and a[j - gap] > value:
                a[j] = a[j - gap]
                j -= gap
            a[j] = value
        gap //= 2
    return a


if __name__ == "__main__":
    print(shell_sort([5, 1, 4, 2, 8]))
