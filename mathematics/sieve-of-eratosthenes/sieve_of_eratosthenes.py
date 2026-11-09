def sieve_of_eratosthenes(limit):
    if limit < 2:
        return []
    prime = [True] * (limit + 1)
    prime[0] = prime[1] = False
    for p in range(2, int(limit ** 0.5) + 1):
        if prime[p]:
            prime[p*p:limit+1:p] = [False] * (((limit - p*p) // p) + 1)
    return [i for i, yes in enumerate(prime) if yes]
if __name__ == "__main__":
    print(sieve_of_eratosthenes(30))
