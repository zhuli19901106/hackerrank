#https://www.hackerrank.com/contests/projecteuler/challenges/euler022
import re

def main():
	n = int(raw_input())
	a = []
	ns = []
	m = {}
	for i in range(n):
		a.append(raw_input().strip())
	a.sort()
	ns = [sum(map(lambda x: ord(x) - ord('A') + 1, list(a[i]))) * (i + 1) for i in xrange(n)]
	for i in xrange(n):
		m[a[i]] = ns[i]
	q = int(raw_input())
	for i in xrange(q):
		print(m[raw_input().strip()])

if __name__ == '__main__':
	main()
