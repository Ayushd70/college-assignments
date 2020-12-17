def maxmin(a, b, c):
    if a < b:
        a, b = b, a
    if a < c:
        a, c = c, a
    if b < c:
        c, b = b, c
    return (a, c)


a, b, c = list(map(int, input("Enter 3 number: ").split()))
print("max={} ,min={}".format(*maxmin(a, b, c)))
