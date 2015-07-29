import re

def main():
	mod = 1234567
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		sum = 1
		a = map(int, re.split(' ', raw_input()))
		for i in xrange(0, n - 1):
			sum = sum * a[i] % mod
		print(sum)

if __name__ == '__main__':
	main()
