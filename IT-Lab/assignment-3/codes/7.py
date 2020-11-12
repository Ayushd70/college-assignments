x = "start"
total = 0
lst = []

n = 1
while x != "done":
    try:
        x = input("Enter a number or enter done to exit: ")
        total += int(x)
        lst.append(int(x))
        n += 1
    except:
        print("Error. Please enter numeric input ")


print("The maximum number is ", max(lst))
print("The minimum number is ", min(lst))

print("Average = ", (total / n))