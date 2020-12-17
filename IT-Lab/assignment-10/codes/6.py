def printfav(l):
    print("You Like To Read ")
    for k in list1:
        print(k, " ")


list1 = []
n = int(input("Enter No.Of Subjects:"))
for i in range(1, n + 1):
    s = input("Enter Subject:")
    list1.append(s)
printfav(list1)
