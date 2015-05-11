import re

def main():
	t = int(raw_input())
	for ti in xrange(t):
		a, b = re.split(' ', raw_input())
		a = int(a)
		b = int(b)
		while b > a:
			b = b & (b - 1)
		print(a & b)

if __name__ == '__main__':
	main()
