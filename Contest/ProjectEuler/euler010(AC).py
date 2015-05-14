#https://www.hackerrank.com/contests/projecteuler/challenges/euler010
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
	return b

def main():
	N = 10 ** 6
	b = sieve(N)
	sum = [0 for i in xrange(1 + N)]
	for i in xrange(1, N + 1):
		sum[i] = sum[i - 1] + i if b[i] else sum[i - 1]
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		print(sum[n])

if __name__ == '__main__':
	main()
