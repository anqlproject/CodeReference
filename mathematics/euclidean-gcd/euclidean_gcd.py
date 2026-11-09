def euclidean_gcd(a, b):
    a, b = abs(a), abs(b)
    while b:
        a, b = b, a % b
    return a
if __name__ == "__main__":
    print(euclidean_gcd(48, 18))
