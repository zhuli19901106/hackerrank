import re

n = int(raw_input())
a = tuple(map(int, re.split(' ', raw_input())))
print(hash(a))
