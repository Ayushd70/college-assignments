def check(s1, s2):
    if s1 == s2[::-1]:
        print("Given string is Palindrome")
    else:
        print("Given string is not Palindrome.")


s1 = input()
s2 = input()

if len(s1) == len(s2):
    check(s1, s2)
