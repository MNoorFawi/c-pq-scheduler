import sys

file = sys.argv[1]

with open(file, "r") as f:
    numbers = f.read().splitlines()

numbers = [int(i) for i in numbers]
print("\n\tSum of number list in python is: %d" % sum(numbers))