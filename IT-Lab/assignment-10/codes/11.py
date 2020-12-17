import sys

print("count: ", (len(sys.argv) - 1))
print("Program name: ", sys.argv[0].split("\\")[-1])
print(" ".join(sys.argv[1:]))
