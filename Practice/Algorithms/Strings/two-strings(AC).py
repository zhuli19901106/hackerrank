import re

def main():
	t = int(raw_input())
	for ti in xrange(t):
		a = set(raw_input().strip())
		b = set(raw_input().strip())
		print('YES' if len(a & b) > 0 else 'NO')

if __name__ == '__main__':
	main()
