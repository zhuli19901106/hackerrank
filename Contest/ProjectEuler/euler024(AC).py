#https://www.hackerrank.com/contests/projecteuler/challenges/euler024
import re

def get_permutation(k, n, f):
	d = range(n)
	p = []
	for i in xrange(n - 1, -1, -1):
		r = k / f[i]
		k %= f[i]
		p.append(d[r])
		del d[r]
	return p

def main():
	N = 13
	f = [1]
	for i in xrange(1, N + 1):
		f.append(f[i - 1] * i)
	t = int(raw_input())
	for ti in range(t):
		n = int(raw_input()) - 1
		a = get_permutation(n, N, f)
		a = ''.join(map(lambda x: chr(x + ord('a')), a))
		print(a)

if __name__ == '__main__':
	main()
