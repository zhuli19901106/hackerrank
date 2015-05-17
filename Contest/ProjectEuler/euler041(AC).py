#https://www.hackerrank.com/contests/projecteuler/challenges/euler041
import bisect

p = 0

def sieve(n):
	global p
	
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

def isprime(n):
	global p
	
	i = 0
	while p[i] <= n / p[i]:
		if n % p[i] == 0:
			return False
		i += 1
	return True

def next_permutation(s):
	n = len(s)
	i = n - 2
	while i >= 0 and s[i] >= s[i + 1]:
		i -= 1
	if i == -1:
		return False
	j = i + 1
	while j < n and s[i] < s[j]:
		j += 1
	j -= 1
	s[i], s[j] = s[j], s[i]
	s1 = s[i + 1: ]
	s1.reverse()
	s[i + 1: ] = s1
	
	return True

def find_primes(ans, n):
	s = [i + 1 for i in xrange(n)]
	while True:
		n = int(''.join(map(str, s)))
		if isprime(n):
			ans.append(n)
		if not next_permutation(s):
			return

def main():
	sieve(120000)
	a = []
	c = [4, 7]
	for i in c:
		find_primes(a, i)
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		i = bisect.bisect_right(a, n)
		print(a[i - 1] if i > 0 else -1)

if __name__ == '__main__':
	main()