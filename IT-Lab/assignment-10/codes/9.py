def fact(n):
    for i in range(1, n):
        n *= i
    return n


def comb(n, r):
    c = fact(n) / (fact(r) * fact(n - r))
    return c


n, r = list(map(int, input("Enter n & c of C(n,r): ").split()))
print(f"C({n},{r})={comb(n,r)}")
