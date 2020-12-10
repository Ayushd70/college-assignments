strings = ["This", "is", "Python"]
i = 0
alphabet = input("Enter an alphabet")

while i < len(strings):
    if alphabet == strings[i][0]:
        print(strings[i])
    i += 1