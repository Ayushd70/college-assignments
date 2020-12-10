List = [1, 2, (1, 2), 3]
c = 0
while not isinstance(List[c], tuple):
    c = c + 1
print(c)