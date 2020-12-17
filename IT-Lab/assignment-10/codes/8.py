def fact(n):
    for i in range(1, n):
        n *= i
    return n


def parmu(n, r):
    c = fact(n) / fact(n - r)
    return c


n, r = list(map(int, input("Enter n & c of P(n,r): ").split()))
print(f"C({n},{r})={parmu(n,r)}")
