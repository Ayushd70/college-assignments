print("Enter temprature in Centigrade: ")
temp_input = float(input())
print(
    "%.2f degree Centigrade is equal to" % temp_input,
    ((temp_input * 9 / 5) + 32),
    "degree Fahrenheit.",
)
