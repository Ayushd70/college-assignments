stu = {}


def checkAndUpdate(name):
    if name in stu:
        print(f"{name}'s DOB is {stu[name]}")
    else:
        try:
            dob = tuple(map(int, input(f"Enter {name}'s DOB(dd-mm-yyyy): ").split("-")))
            stu[name] = dob
        except:
            print(" bad input ")


while True:
    a = input("Enter a name: ")
    checkAndUpdate(a)
    if input("y(y/n) to continue: ") != "y":
        break
for i in sorted(stu):
    print(f"{i}'s DOB is {stu[i]}")