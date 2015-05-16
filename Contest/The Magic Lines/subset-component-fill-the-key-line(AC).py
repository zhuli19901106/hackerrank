# Enter your code here. Read input from STDIN. Print output to STDOUT
def find(l, i):
	if l[i]!=i: l[i] = find(l, l[i])
	return l[i]

def go():
	n = input()
	d = map(int, raw_input().split())
	l = range(n)
	for i in range(n):
		for j in range(i):
			if d[i]&d[j]:
				fi = find(l, i)
				fj = find(l, j)
				l[fi] = l[fj]
	q = [[] for i in range(n)]
	for i in range(n):
		q[find(l,i)].append(d[i])
	res = 64<<n
	for i in range(n):
		if q[i]:
			lq = len(q[i])
			v = (64<<lq) - f(lq, q[i])
			#****FILL THE MISSING LINE HERE****
			res -= v << n - lq
	print res

def f(n, d):
	res = 64
	dp = [0]*(1<<n)
	dp[0] = [1<<i for i in range(64)]
	for i in range(1, 1<<n):
		for j in range(n):
			if i&(1<<j): break
		v = d[j]
		q = dp[i&(i-1)]
		if v:
			l = []
			for x in q:
				if x&v: v|=x
				else: l.append(x)
			l.append(v)
			res += len(l)
			dp[i] = l
		else:
			res += len(q)
			dp[i] = q
	return res

go()
