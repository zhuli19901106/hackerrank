import re

def main():
	t = int(raw_input())
	for ti in range(t):
		n = long(raw_input())
		n1 = n
		c = 0
		while n1 > 0:
			d = n1 % 10
			n1 /= 10
			if d == 0 or n % d != 0:
				continue
			c += 1
		print(c)

if __name__ == '__main__':
	main()
