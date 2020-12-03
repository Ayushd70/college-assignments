dict_m_to_cm = {}
dict_cm_to_m = {}

choice = 0
while choice != 3:
    choice = int(
        input(
            "Enter 1 for meter to centimeter\nEnter 2 for centimeter to meter\nEnter 3 for Exit\n"
        )
    )
    if choice == 1:
        meter = float(input("Enter your value in meter: "))
        dict_m_to_cm[meter] = float(meter * 100)

    elif choice == 2:
        centimeter = float(input("Enter your value in centimeter: "))
        dict_cm_to_m[centimeter] = float(centimeter / 100)

    else:
        print("Wrong Choice")

print("Meter to Centimeter:", dict_m_to_cm)
print("Centimeter to Meter:", dict_cm_to_m)
