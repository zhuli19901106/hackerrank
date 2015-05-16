#https://www.hackerrank.com/contests/projecteuler/challenges/euler018
import re

def main():
	t = int(raw_input())
	for ti in range(t):
		n = int(raw_input())
		a = []
		for i in xrange(n):
			a.append(map(int, re.split(' ', raw_input().strip())))
		sum = [[0 for j in xrange(i + 1)] for i in xrange(n)]
		sum[0][0] = a[0][0]
		for i in xrange(1, n):
			sum[i][0] = sum[i - 1][0] + a[i][0]
			sum[i][i] = sum[i - 1][i - 1] + a[i][i]
		for i in xrange(2, n):
			for j in xrange(1, i):
				sum[i][j] = max(sum[i - 1][j], sum[i - 1][j - 1]) + a[i][j]
		ans = sum[n - 1][0]
		for i in xrange(1, n):
			ans = max(ans, sum[n - 1][i])
		print(ans)

if __name__ == '__main__':
	main()
