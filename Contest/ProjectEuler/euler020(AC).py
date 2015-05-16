#https://www.hackerrank.com/contests/projecteuler/challenges/euler020
import math
import re

def main():
	t = int(raw_input())
	for ti in range(t):
		print(sum(map(int, list(str(math.factorial(int(raw_input())))))))

if __name__ == '__main__':
	main()
