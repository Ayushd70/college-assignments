with open("test.txt", "r") as inp:
    y = inp.read().swapcase()
with open("write.txt", "a") as out:
    out.write(y)