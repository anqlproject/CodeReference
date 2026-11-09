from __future__ import annotations


def heap_sort(values: list[int]) -> list[int]:
    a = list(values)
    def sift(root: int, end: int) -> None:
        while 2 * root + 1 <= end:
            child = 2 * root + 1
            if child + 1 <= end and a[child] < a[child + 1]: child += 1
            if a[root] >= a[child]: return
            a[root], a[child] = a[child], a[root]
            root = child
    for root in range(len(a) // 2 - 1, -1, -1): sift(root, len(a) - 1)
    for end in range(len(a) - 1, 0, -1):
        a[0], a[end] = a[end], a[0]
        sift(0, end - 1)
    return a


if __name__ == "__main__":
    print(heap_sort([5, 1, 4, 2, 8]))
