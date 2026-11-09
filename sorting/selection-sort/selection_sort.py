from __future__ import annotations


def selection_sort(values: list[int]) -> list[int]:
    a = list(values)
    for i in range(len(a)): 
        smallest = min(range(i, len(a)), key=a.__getitem__)
        a[i], a[smallest] = a[smallest], a[i]
    return a


if __name__ == "__main__":
    print(selection_sort([5, 1, 4, 2, 8]))
