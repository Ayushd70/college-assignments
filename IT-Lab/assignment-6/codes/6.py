l1 = list(map(int, input("Enter 1st list :").split()))
l2 = list(map(int, input("Enter 2nd list :").split()))

if l1 == l2:
    print(f" {l1} and {l2} are equal ")
elif sorted(l1) == sorted(l2):
    print(f" {l1} and {l2} have same elements ")
else:
    print(f" {l1} and {l2} are not equal ")