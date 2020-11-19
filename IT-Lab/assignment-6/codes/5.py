r, c = list(map(int, input("Enter row & column:").split()))

table = [list(map(int, input().split())) for _ in range(r)]

print("output:")
for i in table:
    print(" ".join(list(map(str, i))))
