rate = int(input("Rate:"))
hours = int(input("Hours:"))
if hours <= 40:
    pay = hours * rate
else:
    pay = 40 * rate + 1.5 * rate * (hours - 40)
print("Pay :", pay)