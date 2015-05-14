#https://www.hackerrank.com/contests/projecteuler/challenges/euler007
import re

def sieve(n):
	b = [True for i in xrange(n + 1)]
	i = 2
	b[0] = b[1] = False
	while i <= n // i:
		if not b[i]:
			i += 1
			continue
		j = i
		while j <= n // i:
			b[i * j] = False
			j += 1
		i += 1
	p = []
	for i in xrange(n + 1):
		if b[i]:
			p.append(i)
	return p

def main():
	p = sieve(110000)
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		print(p[n - 1])

if __name__ == '__main__':
	main()
