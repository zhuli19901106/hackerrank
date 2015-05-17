#https://www.hackerrank.com/contests/projecteuler/challenges/euler034
import math
import re

def test(n):
	return sum([math.factorial(val) for val in map(int, list(str(n)))]) % n == 0

def main():
	N = 100000
	a = [0 for i in xrange(N + 1)]
	for i in xrange(10, N + 1):
		a[i] = a[i - 1] + i if test(i) else a[i - 1]
	
	n = int(raw_input())
	print(a[n - 1])

if __name__ == '__main__':
	main()
