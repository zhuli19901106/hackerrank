import re

def count_sum(n, k):
	n -= 1
	n /= k
	return n * (n + 1) / 2 * k

def main():
	t = int(raw_input())
	for ti in range(t):
		n = int(raw_input())
		print(count_sum(n, 3) + count_sum(n, 5) - count_sum(n, 15))

if __name__ == '__main__':
	main()
