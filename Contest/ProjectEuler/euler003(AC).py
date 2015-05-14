#https://www.hackerrank.com/contests/projecteuler/challenges/euler003
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
	p = sieve(10 ** 6 + 5)
	pc = len(p)
	
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		i = 0
		max_prime = 0
		while p[i] <= n // p[i]:
			if n % p[i] != 0:
				i += 1
				continue
			max_prime = p[i]
			while n % p[i] == 0:
				n /= p[i]
			i += 1
		if n > 1:
			max_prime = n
			n = 1
		print(max_prime)

if __name__ == '__main__':
	main()
