bill = {"cpu": 10, "gpu": 20, "ram": 30, "cabinet": 40, "sps": 50}
x = input("enter items=")
a = 0
list = x.split()
for key in bill:
    for item in list:
        if key == item:
            a = a + bill[key]
for key in bill:
    print(key, "       ", bill[key], "\n")
print("total=", a)
