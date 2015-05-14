#https://www.hackerrank.com/contests/projecteuler/challenges/euler011
import re

def main():
	a = []
	n = 20
	for i in xrange(n):
		a.append(map(int, re.split(' ', raw_input().strip())))
	ans = 0
	for i in xrange(n):
		for j in xrange(n - 3):
			ans = max(ans, a[i][j] * a[i][j + 1] * a[i][j + 2] * a[i][j + 3])
			ans = max(ans, a[j][i] * a[j + 1][i] * a[j + 2][i] * a[j + 3][i])
	for i in xrange(n - 3):
		for j in xrange(n - 3):
			ans = max(ans, a[i][j] * a[i + 1][j + 1] * a[i + 2][j + 2] * a[i + 3][j + 3])
			ans = max(ans, a[i + 3][j] * a[i + 2][j + 1] * a[i + 1][j + 2] * a[i][j + 3])
	print(ans)

if __name__ == '__main__':
	main()
