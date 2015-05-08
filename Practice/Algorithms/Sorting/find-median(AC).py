import re

'''
7
0 1 2 4 6 5 3
'''

def main():
	M = 10000
	n = int(raw_input())
	a = map(int, re.split(' ', raw_input()))
	c = [0 for i in xrange(0, 2 * M + 1)]
	for i in xrange(0, n):
		c[a[i] + M] += 1
	sum = 0
	for i in xrange(0, 2 * M + 1):
		sum += c[i]
		if sum >= (n + 1) / 2:
			print(i - M)
			break

if __name__ == '__main__':
	main()
