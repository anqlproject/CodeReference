def fast_exponentiation(base, exponent):
    # Integer exponent; negative exponents return a floating-point reciprocal.
    if exponent < 0:
        return 1 / fast_exponentiation(base, -exponent)
    result = 1
    while exponent:
        if exponent & 1:
            result *= base
        base *= base
        exponent >>= 1
    return result
if __name__ == "__main__":
    print(fast_exponentiation(2, 10))
