import re

def main():
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		a = map(int, re.split(' ', raw_input()))
		ans = 0
		for i in xrange(n):
			if ((i + 1) & 1) == 1 and ((n - i) & 1) == 1:
				ans ^= a[i]
		print(ans)

if __name__ == '__main__':
	main()
