#https://www.hackerrank.com/contests/projecteuler/challenges/euler006
import re

def main():
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		print((n * (n + 1) / 2) ** 2 - n * (n + 1) * (2 * n + 1) / 6)

if __name__ == '__main__':
	main()
