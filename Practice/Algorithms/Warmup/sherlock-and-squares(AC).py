import math
import re

def count(n):
	return int(math.sqrt(n - 1))

def main():
	t = int(raw_input())
	for ti in range(t):
		a, b = re.split(' ', raw_input())
		a = int(a)
		b = int(b) + 1
		print(count(b) - count(a))

if __name__ == '__main__':
	main()
