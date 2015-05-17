#https://www.hackerrank.com/contests/projecteuler/challenges/euler028
import re

#a[1] = 3
#a[2] = 13
#a[3] = 31
#a[n] = 4 * n ^ 2 - 2 * n + 1
#b[n] = 16 * n ^ 2 + 4 * n + 4
#s[n] = 1 + b[1] + b[2] + ...
#s[n] = 

def main():
	MOD = 10 ** 9 + 7
	t = int(raw_input())
	for ti in range(t):
		n = int(raw_input()) / 2
		sum = (1 + 16 * n * (n + 1) * (2 * n + 1) / 6 + 4 * n * (n + 1) / 2 + 4 * n) % MOD
		print(sum)

if __name__ == '__main__':
	main()
