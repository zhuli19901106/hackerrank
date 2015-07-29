# 2D Rabin-Karp Algorithm
import re

MOD = 10 ** 9 + 7

def get2DMatrix(n, m):
    a = [[0 for j in xrange(m)] for i in xrange(n)]
    return a
    
def calcHash(a, nn, mm):
    n = len(a)
    m = len(a[0])
    
    b = 1
    for i in xrange(mm):
        b = b * 10 % MOD
    b2 = 1
    for i in xrange(nn):
        b2 = b2 * b % MOD
    
    h = get2DMatrix(n, m)
    for i in xrange(n):
        val = 0
        for j in xrange(m):
            val = (val * 10 + a[i][j]) % MOD
            if j >= mm:
                val = (val + a[i][j - mm] * (MOD - b)) % MOD
            h[i][j] = val
            
    h2 = get2DMatrix(n, m)
    h2[0] = h[0][:]
    for i in xrange(1, n):
        for j in xrange(m):
            h2[i][j] = (h2[i - 1][j] * b + h[i][j]) % MOD
            if i >= nn:
                h2[i][j] = (h2[i][j] + h[i - nn][j] * (MOD - b2)) % MOD
    return h, h2

def equal(a, p, ai, aj):
    np = len(p)
    mp = len(p[0])
    for i in xrange(np):
        for j in xrange(mp):
            if a[ai + i][aj + j] != p[i][j]:
                return False
    return True
    
def solve():
    na, ma = map(int, re.split('\s+', raw_input().strip()))
    a = []
    for i in xrange(na):
        a.append(map(int, list(raw_input().strip())))
    np, mp = map(int, re.split('\s+', raw_input().strip()))
    p = []
    for i in xrange(np):
        p.append(map(int, list(raw_input().strip())))
    ha, h2a = calcHash(a, np, mp)
    hp, h2p = calcHash(p, np, mp)
    
    for i in xrange(np - 1, na):
        for j in xrange(mp - 1, ma):
            if h2a[i][j] != h2p[np - 1][mp - 1]:
                continue
            if equal(a, p, i - np + 1, j - mp + 1):
                print('YES')
                return
    print('NO')
    
if __name__ == '__main__':
    t = int(raw_input())
    for ti in xrange(t):
        solve()
        