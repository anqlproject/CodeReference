from __future__ import annotations


def merge_sort(values: list[int]) -> list[int]:
    a = list(values)
    def merge_sort(lo: int, hi: int) -> None:
        if hi - lo < 2:
            return
        mid = (lo + hi) // 2
        merge_sort(lo, mid)
        merge_sort(mid, hi)
        left, right = a[lo:mid], a[mid:hi]
        i = j = 0
        for k in range(lo, hi):
            if j == len(right) or (i < len(left) and left[i] <= right[j]):
                a[k] = left[i]
                i += 1
            else:
                a[k] = right[j]
                j += 1
    merge_sort(0, len(a))
    return a


if __name__ == "__main__":
    print(merge_sort([5, 1, 4, 2, 8]))
