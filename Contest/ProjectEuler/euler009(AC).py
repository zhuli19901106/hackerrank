#https://www.hackerrank.com/contests/projecteuler/challenges/euler009
import math
import re

def solve(n):
	a = 1
	ans = -1
	while a * 3 + 3 <= n:
		b = 1.0 * n * (n - 2 * a) / (2 * n - 2 * a)
		if not (a < b and b < n - a - b):
			break
		if b == int(b):
			b = int(b)
			ans = max(ans, a * b * (n - a - b))
		a += 1
	return ans

def main():
	N = 3000
	a = [-1 for i in xrange(N + 1)]
	for i in xrange(1, N + 1):
		a[i] = solve(i)
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		print(a[n])

if __name__ == '__main__':
	main()
