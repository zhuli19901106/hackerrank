import re

def main():
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		ans = 0
		b = 1 << 64
		while n != 1:
			while n & b == 0:
				b >>= 1
			if n ^ b == 0:
				n >>= 1
				b >>= 1
			else:
				n ^= b
				b >>= 1
			ans += 1
		print('Louise' if ans & 1 else 'Richard')

if __name__ == '__main__':
	main()
