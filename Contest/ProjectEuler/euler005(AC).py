#https://www.hackerrank.com/contests/projecteuler/challenges/euler005
import re

def lcm(x, y):
	return x / gcd(x, y) * y

def gcd(x, y):
	return y if x == 0 else gcd(y % x, x)

def main():
	t = int(raw_input())
	a = [0, 1]
	for i in xrange(2, 41):
		a.append(lcm(i, a[i - 1]))
	for ti in xrange(t):
		n = int(raw_input())
		print(a[n])

if __name__ == '__main__':
	main()
