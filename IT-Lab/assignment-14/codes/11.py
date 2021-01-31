def calc(n):
    num = []
    average = 0
    median = 0
    mode = 0
    for i in range(1, n + 1):
        num.append(i)
    average = sum(num) // len(num)
    median = sorted(num)[len(num) // 2]
    mode = max(num, key=num.count)

    print(f"Average: {average}\nMedian: {median}\nMode:{mode}")


inp = eval(input("Enter a number: "))

calc(inp)