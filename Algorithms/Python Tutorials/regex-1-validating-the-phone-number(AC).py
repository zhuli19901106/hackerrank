import re

def main():
	n = int(raw_input())
	for i in range(n):
		s = raw_input()
		if re.match('^[7-9]\d{9,9}$', s):
			print('YES')
		else:
			print('NO')

if __name__ == '__main__':
	main()
