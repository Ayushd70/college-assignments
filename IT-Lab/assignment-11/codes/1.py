def leapYear(year):
    if (year % 400 == 0) or ((year % 4 == 0) and (year % 100 != 0)):
        print("%d is a Leap Year" % year)


for i in range(1000, 2021):
    leapYear(i)