data = {"apple": 5600.00, "orange": 3500.00, "banana": 5000.00}

sorted_data = {key: data[key] for key in sorted(data)}
print(sorted_data)


print(is_empty(data))