import re

def get2DMatrix(n, m, val):
    return [[val for j in xrange(m)] for i in xrange(n)]
    
def rotate(a, r):
    # n is guaranteed to be even
    n = len(a)
    m = len(a[0])
    s = getDisplace(n, m)
    s = displacePow(s, r)
    b = get2DMatrix(n, m, 0)
    for i in xrange(n):
        for j in xrange(m):
            b[i][j] = a[s[i * m + j] / m][s[i * m + j] % m]
    return b
    
def getDisplace(n, m):
    s = range(n * m)
    i = 0
    while i < n / 2 and i < m / 2:
        rr = n - 2 * i
        cc = m - 2 * i
        for j in xrange(1, rr, 1):
            #left
            s[(j + i) * m + i] = (j - 1 + i) * m + i
        for j in xrange(1, cc, 1):
            #down
            s[(rr - 1 + i) * m + (j + i)] = (rr - 1 + i) * m + (j - 1 + i)
        for j in xrange(rr - 2, -1, -1):
            #right
            s[(j + i) * m + (cc - 1 + i)] = (j + 1 + i) * m + (cc - 1 + i)
        for j in xrange(cc - 2, -1, -1):
            #top
            s[i * m + (j + i)] = i * m + (j + 1 + i)
        i += 1
    return s

def multiply(a, b):
    n = len(a)
    c = []
    for i in xrange(n):
        c.append(a[b[i]])
    return c
    
def displacePow(a, k):
    if k == 1:
        return a[:]
    a2 = displacePow(a, k >> 1)
    if k & 1:
        return multiply(multiply(a2, a2), a)
    else:
        return multiply(a2, a2)
    
if __name__ == '__main__':
    n, m, r = map(int, re.split('\s+', raw_input().strip()))
    a = []
    for i in xrange(n):
        a.append(map(int, re.split('\s+', raw_input().strip())))
    a = rotate(a, r)
    for i in xrange(n):
        print(' '.join(map(str, a[i])))
        