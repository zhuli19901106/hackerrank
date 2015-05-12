import re

def main():
	n = int(raw_input())
	ans = set(raw_input().strip())
	for i in xrange(1, n):
		ans = ans & set(raw_input().strip())
	print(len(ans))

if __name__ == '__main__':
	main()
