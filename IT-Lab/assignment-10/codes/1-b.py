# Fibonacci series up to nth term using Non-Recursion
def gen_fibo(n):
    a = 0
    b = 1
    sum = 0
    count = 1
    print("Fibonacci Series: ", end=" ")
    while count <= n:
        print(sum, end=" ")
        count += 1
        a = b
        b = sum
        sum = a + b


n1 = int(input("Enter the value of 'n': "))
gen_fibo(n1)