def init(str):
    a = str[0].upper()
    for i in range(1, len(str)):
        if str[i] == " ":
            print(a, str[i + 1].upper())


str = "Ayush Dubey"
init(str)
