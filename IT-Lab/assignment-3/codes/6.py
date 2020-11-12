num = 0
tot = 0.0
while True:
    number = input("Enter a number:")
    if number == "done":
        break
    try:
        num1 = float(number)
    except:
        print("Invalid Input")
        continue
    num = num + 1
    tot = tot + num1
print("all done")
print("Total = ", tot)
print("Count = ", num)
print("Average = ", tot / num)
