def add(x, y):
    sum = int(x) + int(y)
    return sum


def sub(x, y):
    dif = int(max(x, y)) - int(min(x, y))
    return dif


def mul(x, y):
    pro = int(x) * int(y)
    return pro


def div(x, y):
    q = int(x) // int(y)
    r = int(x) % int(y)
    print("Quotient=", q)
    print("Remainder=", r)


def expo(x, y):
    e = int(x) ** int(y)
    return e


x = 9
while x != 0:

    print(
        "Enter 1 For Addition,2 For Subtraction,3 For Multiplication,4 For Division,5 For Exponent,0 For Exit"
    )
    x = int(input("Enter Your Choice:"))
    if x == 1:
        a, b = input("Enter 2 No.:").split(",")
        s = add(a, b)
        print("Sum=", s)
    elif x == 2:
        a, b = input("Enter 2 No.:").split(",")
        s = sub(a, b)
        print("Diff=", s)
    elif x == 3:
        a, b = input("Enter 2 No.:").split(",")
        s = mul(a, b)
        print("Product=", s)
    elif x == 4:
        a = int(input("Enter Dividend:"))
        b = int(input("Enter Divisor:"))
        div(a, b)
    elif x == 5:
        a, b = input("Enter 2 No.:").split(",")
        s = expo(a, b)
        print("x^y=", s)
    else:
        break
