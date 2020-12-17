def simInt(a, t, age):
    i = 12 if (age >= 60) else 10
    return a * (i / 100 * t)


a = int(input("Enter the amount: "))
t = int(input("Enter the time interval(years): "))
ag = int(input("Enter the age: "))
print("simple interest = ", simInt(a, t, ag))
