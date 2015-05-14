#https://www.hackerrank.com/contests/projecteuler/challenges/euler015
import re

def main():
	MOD = 10 ** 9 + 7
	N = 500
	a = [[1 for j in xrange(N + 1)] for i in xrange(N + 1)]
	for i in xrange(1, N + 1):
		for j in xrange(1, N + 1):
			a[i][j] = (a[i][j - 1] + a[i - 1][j]) % MOD
	t = int(raw_input())
	for ti in range(t):
		n, m = re.split(' ', raw_input())
		n = int(n)
		m = int(m)
		print(a[n][m])

if __name__ == '__main__':
	main()
