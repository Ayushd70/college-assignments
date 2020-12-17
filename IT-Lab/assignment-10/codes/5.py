def volume(l):
    v = l[0] * l[1] * l[2]
    return v


list1 = []
n = int(input("Enter No.Of Elements(Max:3):"))
for i in range(1, n + 1):
    x = int(input("Enter No.:"))
    list1.append(x)
l1 = len(list1)
if l1 < 3:
    d = 3 - l1
    for i in range(1, d + 1):
        list1.append(1)
vol = volume(list1)
print("Volume=", vol)
