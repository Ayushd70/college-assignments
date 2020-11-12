try:
    print("Enter Hours: ")
    hrs = int(input())
    print("Enter Rate: ")
    rate = int(input())
    print("Pay:", hrs * rate)
except ValueError:
    print("Error, please enter numeric input")
