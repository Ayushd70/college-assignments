dictionary = {"One": 1, "Two": 2, "Three": 3, "Four": 4, "Five": 5}
my_inverted_dict = dict()

for key, value in dictionary.items():
    my_inverted_dict.setdefault(value, list()).append(key)

print(my_inverted_dict)