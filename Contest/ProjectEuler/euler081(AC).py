#https://www.hackerrank.com/contests/projecteuler/challenges/euler081
import re

def main():
	n = int(raw_input())
	a = []
	dp = [[0 for j in xrange(n)] for i in xrange(n)]
	for i in xrange(n):
		a.append(map(int, re.split('\s', raw_input().strip())))
	dp[0][0] = a[0][0]
	for i in xrange(1, n):
		dp[0][i] = dp[0][i - 1] + a[0][i]
		dp[i][0] = dp[i - 1][0] + a[i][0]
	for i in xrange(1, n):
		for j in xrange(1, n):
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j]
	print(dp[n - 1][n - 1])

if __name__ == '__main__':
	main()
