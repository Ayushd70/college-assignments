lst = [None] * 1000
lst[0] = 0
lst[1] = 1
for i in range(2, 1000):
    lst[i] = lst[i - 1] + lst[i - 2]

print(lst)