#https://www.hackerrank.com/contests/projecteuler/challenges/euler008
import re

def main():
	t = int(raw_input())
	for ti in xrange(t):
		n, k = re.split(' ', raw_input())
		n = int(n)
		k = int(k)
		a = map(int, list(raw_input()))
		i = 0
		ans = 0
		p = 1
		ll = 0
		while i < n:
			if a[i] == 0:
				ll = 0
				p = 1
				i += 1
				continue
			if ll < k:
				ll += 1
				p *= a[i]
				i += 1
			else:
				p = p / a[i - k] * a[i]
				i += 1
			if ll == k:
				ans = max(ans, p)
		print(ans)

if __name__ == '__main__':
	main()
