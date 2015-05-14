#https://www.hackerrank.com/contests/projecteuler/challenges/euler012
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

def count_divisor(n, p):
	ans = 1
	i = 0
	while p[i] <= n / p[i]:
		if n % p[i] != 0:
			i += 1
			continue
		c = 1
		while n % p[i] == 0:
			n /= p[i]
			c += 1
		ans *= c
		i += 1
	if n > 1:
		ans *= 2
		n = 1
	return ans

def main():
	N = 1000
	p = sieve(10 ** 6)
	ans = [0 for i in xrange(N + 1)]
	i = 1
	j = 0
	while True:
		cc = count_divisor(i * (i + 1) / 2, p)
		while j < cc and j <= N:
			ans[j] = i * (i + 1) / 2
			j += 1
		if j > N:
			break
		i += 1
	#print('[' + ', '.join(map(str, ans)) + ']')
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		print(ans[n])

if __name__ == '__main__':
	main()
