#https://www.hackerrank.com/contests/projecteuler/challenges/euler080
# Apparently the built-in APIs are not fast enough.
import decimal
import math
import re

def calc_sqrt(n, p):
	return decimal._sqrt_nearest(int(str(n) + ''.zfill(2 * p)), 1)

def main():
	n = int(raw_input())
	p = int(raw_input())
	total_sum = 0
	for i in xrange(2, n + 1):
		if int(math.sqrt(i)) ** 2 == i:
			continue
		rt = map(int, list(str(calc_sqrt(i, p)))[: p])
		total_sum += sum(rt)
	print(total_sum)

if __name__ == '__main__':
	main()
