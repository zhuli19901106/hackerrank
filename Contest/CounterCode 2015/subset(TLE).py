import re

N = 16
s = [{} for i in xrange(N + 1)]

def add(val):
    b = 1
    for i in xrange(N):
        if val & b:
            b <<= 1
            continue
        if val not in s[i]:
            s[i][val] = 1
        else:
            s[i][val] += 1
        b <<= 1
    if val not in s[N]:
        s[N][val] = 1
    else:
        s[N][val] += 1

def delete(val):
    b = 1
    for i in xrange(N):
        if val & b:
            b <<= 1
            continue
        if s[i][val] > 1:
            s[i][val] -= 1
        else:
            del s[i][val]
        b <<= 1
    if s[N][val] > 1:
        s[N][val] -= 1
    else:
        del s[N][val]
        
def cnt(val):
    b = 1
    res = s[N]
    for i in xrange(N):
        if val & b:
            b <<= 1
            continue
        nres = {}
        k = set(res.keys()) & set(s[i].keys())
        for ki in k:
            nres[ki] = res[ki]
        res = nres
        b <<= 1
    print(sum(res.values()))
        
fun = {}
fun['add'] = add
fun['del'] = delete
fun['cnt'] = cnt

if __name__ == '__main__':
    q = int(raw_input().strip())
    for qi in xrange(q):
        op, val = re.split('\s+', raw_input().strip())
        val = int(val)
        fun[op](val)
        