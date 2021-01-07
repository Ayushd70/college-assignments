import datetime

now = datetime.datetime.now()

print("Current year: ", datetime.date.today().strftime("%Y"))
print("Month of year: ", datetime.date.today().strftime("%B"))
print("Day of year: ", datetime.date.today().strftime("%j"))
print(f"Current date and time: {now:%Y-%m-%d %H:%M:%S}")