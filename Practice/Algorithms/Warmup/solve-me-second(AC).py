import re

if __name__ == '__main__':
	n = int(raw_input())
	for i in range(0, n):
		s = raw_input()
		a, b = re.split(' ', s)
		a = int(a)
		b = int(b)
		print(a + b)
