from __future__ import annotations


def bubble_sort(values: list[int]) -> list[int]:
    a = list(values)
    for end in range(len(a) - 1, 0, -1):
        swapped = False
        for i in range(end):
            if a[i] > a[i + 1]:
                a[i], a[i + 1] = a[i + 1], a[i]
                swapped = True
        if not swapped:
            break
    return a


if __name__ == "__main__":
    print(bubble_sort([5, 1, 4, 2, 8]))
