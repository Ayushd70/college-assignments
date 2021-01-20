import difflib

lines1 = """
dog
cat
bird
buffalo
gophers
hound
horse
""".strip().splitlines()

lines2 = """
cat
dog
bird
buffalo
gopher
horse
mouse
""".strip().splitlines()

# Changes:
# swapped positions of cat and dog
# changed gophers to gopher
# removed hound
# added mouse

for line in difflib.unified_diff(
    lines1, lines2, fromfile="file1", tofile="file2", lineterm="", n=0
):
    print(line)
