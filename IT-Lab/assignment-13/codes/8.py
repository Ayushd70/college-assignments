f = open("oldfile.txt", "rb")
s = f.readlines()
f.close()
f = open("newfile.txt", "wb")
s.reverse()
for line in reversed(s):
    f.write(line)
f.close()