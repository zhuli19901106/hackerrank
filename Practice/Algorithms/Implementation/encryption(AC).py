import math
import re

if __name__ == '__main__':
    s = raw_input().strip()
    n = len(s)
    r = int(math.sqrt(n))
    c = r + 1 if n > r * r else r
    r = r + 1 if n > r * r + 1 else r
    ans = []
    for i in xrange(c):
        for j in xrange(r):
            if j * c + i >= n:
                continue
            ans.append(s[j * c + i])
        ans.append(' ')
    ans.pop()
    print(''.join(ans))
    