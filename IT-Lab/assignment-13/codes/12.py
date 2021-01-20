data = data2 = ""

with open("file1") as fp:
    data = fp.read()

with open("file2") as fp:
    data2 = fp.read()

data += "\n"
data += data2

with open("file3.txt", "w") as fp:
    fp.write(data)
