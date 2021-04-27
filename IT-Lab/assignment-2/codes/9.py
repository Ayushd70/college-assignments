def ArmStrong(n):
    l = len(str(n))
    sum = 0
    temp = n

    while temp > 0:
        d = temp % 10
        sum += d ** l
        temp //= 10

    if n == sum:
        return "Armstrong number"
    else:
        return "Not an Armstrong number"


num = int(input())

print(ArmStrong(num))
print(ArmStrong(153))
print(ArmStrong(67))