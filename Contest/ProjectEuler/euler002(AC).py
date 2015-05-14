#https://www.hackerrank.com/contests/projecteuler/challenges/euler002
import re

def main():
	MAXN = 4 * 10 ** 16
	a = [1, 2]
	i = 2
	while True:
		a.append(a[i - 1] + a[i - 2])
		if a[i] > MAXN:
			break
		i += 1
	n = len(a)
	sum = a[: ]
	sum[0] = 0
	for i in xrange(1, n):
		sum[i] = sum[i - 1] if a[i] & 1 else sum[i - 1] + a[i]
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		i = 0
		while a[i] <= n:
			i += 1
		i -= 1
		print(sum[i])

if __name__ == '__main__':
	main()
