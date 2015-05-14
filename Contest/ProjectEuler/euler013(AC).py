#https://www.hackerrank.com/contests/projecteuler/challenges/euler013
import re

def main():
	n = int(raw_input())
	sum = 0
	for i in xrange(n):
		val = int(raw_input().strip())
		sum += val
	print(str(sum)[: 10])

if __name__ == '__main__':
	main()
