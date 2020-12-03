dict_first = {"One": 1, "Two": 2, "Three": 3, "Four": 4, "Five": 5}
result = 1

for key in dict_first:
    result = result * dict_first[key]

print(result)