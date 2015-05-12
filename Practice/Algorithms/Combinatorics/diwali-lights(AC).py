import re

def main():
	mod = 100000
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		ans = 1
		for i in xrange(n):
			ans = ans * 2 % mod
		ans -= 1
		print(ans)

if __name__ == '__main__':
	main()
