#https://www.hackerrank.com/contests/projecteuler/challenges/euler016
import re

def main():
	N = 100000
	MOD = 10 ** 9 + 7
	c = [1, 2, 5, 10, 20, 50, 100, 200]
	dp = [0 for i in xrange(N + 1)]
	dp[0] = 1
	for i in xrange(len(c)):
		for j in xrange(c[i], N + 1):
			dp[j] = (dp[j] + dp[j - c[i]]) % MOD
	t = int(raw_input())
	for ti in range(t):
		n = int(raw_input())
		print(dp[n])

if __name__ == '__main__':
	main()
