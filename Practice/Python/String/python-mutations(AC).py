import re

s = list(raw_input().strip())
i, c = re.split('\s+', raw_input().strip())
i = int(i)
s[i] = c
s = ''.join(s)
print(s)
