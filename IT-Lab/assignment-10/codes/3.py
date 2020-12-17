def compute_gcd(x, y):
    if x > y:
        smaller = y
    else:
        smaller = x
    for i in range(1, smaller + 1):
        if (x % i == 0) and (y % i == 0):
            gcd = i
    return gcd


def gcd(n, l):
    if n == 1:
        return l[0]
    g = l[0]
    for i in l[1:]:
        g = compute_gcd(g, i)
    return g


num = list(map(int, input("Enter numbers: ").split()))
print("The G.C.D. is", gcd(len(num), num))
