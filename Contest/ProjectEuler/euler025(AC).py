#https://www.hackerrank.com/contests/projecteuler/challenges/euler025
import math
import re
'''
# What a pity, only analytical solution works.
def matmul(a, b):
	c = [[0, 0], [0, 0]]
	c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0]
	c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1]
	c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0]
	c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1]
	return c

def matpow(p, n):
	if n == 1:
		return p
	mp = matpow(p, n >> 1)
	ans = matmul(mp, mp)
	if n & 1:
		ans = matmul(ans, p)
	return ans

def fast_fib(n):
	#[0, 1]
	#[1, 1]
	if n < 2:
		return n
	p = [[0, 1], [1, 1]]
	mp = matpow(p, n - 1)
	return mp[1][1]
'''

ff = [0, 1]

def count_fib_digits(n):
	global ff
	
	if n < len(ff):
		return len(str(ff[n]))
	return int(n * math.log10((math.sqrt(5) + 1) / 2) - math.log10(5) / 2) + 1

def main():
	global ff
	
	for i in xrange(2, 51):
		ff.append(ff[i - 2] + ff[i - 1])
	
	# Memorization is needed to avoid timeout.
	ans = {}
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		if n in ans:
			print(ans[n])
			continue
		ll = 1
		rr = 25000
		while rr - ll > 1:
			mm = ll + (rr - ll >> 1)
			f = count_fib_digits(mm)
			if f < n:
				ll = mm
			else:
				rr = mm
		ans[n] = rr
		print(rr)

if __name__ == '__main__':
	main()
