netIncome = {"Rohan": 25379, "Shila": 24662, "Ajay": 26819}
minimum = min(netIncome, key=netIncome.get)
maximum = max(netIncome, key=netIncome.get)

print("Minimum Salary= {} : {}".format(minimum, netIncome[minimum]))
print("Maximum Salary= {} : {}".format(maximum, netIncome[maximum]))