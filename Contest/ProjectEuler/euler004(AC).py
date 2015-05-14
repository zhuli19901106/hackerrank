#https://www.hackerrank.com/contests/projecteuler/challenges/euler004
import bisect
import re

def pal(n):
	s = list(str(n))
	s1 = s[:]
	s1.reverse()
	return s == s1

def main():
	a = []
	for i in xrange(100, 1000):
		for j in xrange(i, 1000):
			if pal(i * j):
				a.append(i * j)
	a = list(set(a))
	a.sort()
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		i = bisect.bisect_left(a, n)
		print(a[i - 1])

if __name__ == '__main__':
	main()
