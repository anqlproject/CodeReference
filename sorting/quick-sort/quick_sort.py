from __future__ import annotations


def quick_sort(values: list[int]) -> list[int]:
    a = list(values)
    def quick_sort(lo: int, hi: int) -> None:
        i, j = lo, hi
        pivot = a[(lo + hi) // 2]
        while i <= j:
            while a[i] < pivot: i += 1
            while a[j] > pivot: j -= 1
            if i <= j:
                a[i], a[j] = a[j], a[i]
                i, j = i + 1, j - 1
        if lo < j: quick_sort(lo, j)
        if i < hi: quick_sort(i, hi)
    if a: quick_sort(0, len(a) - 1)
    return a


if __name__ == "__main__":
    print(quick_sort([5, 1, 4, 2, 8]))
