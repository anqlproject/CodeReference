def linear_search(values, target):
    for i, value in enumerate(values):
        if value == target:
            return i
    return -1
if __name__ == "__main__":
    print(linear_search([4, 2, 7], 2))
