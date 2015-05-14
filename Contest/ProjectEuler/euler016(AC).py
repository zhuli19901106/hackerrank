#https://www.hackerrank.com/contests/projecteuler/challenges/euler016
import re

def main():
	t = int(raw_input())
	for ti in range(t):
		print(sum(map(int, list(str(2 ** int(raw_input()))))))

if __name__ == '__main__':
	main()
