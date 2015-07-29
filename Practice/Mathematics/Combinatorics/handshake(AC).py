import re

def main():
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		print(n * (n - 1) / 2)

if __name__ == '__main__':
	main()
