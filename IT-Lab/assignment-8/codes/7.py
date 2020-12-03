a = int(input("Enter a Value(in meters):"))
mtc = {a: a / 100}
ctm = dict(map(lambda i: (i[1], i[0]), mtc.items()))
print("meters to centimeters ", mtc, "centimeters to meters", ctm)
