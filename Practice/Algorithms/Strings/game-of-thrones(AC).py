import re

def main():
	s = raw_input().strip()
	d = {}
	for val in s:
		if not val in d:
			d[val] = 1
		else:
			d[val] += 1
	odd_count = 0
	for val in d.keys():
		if d[val] & 1:
			odd_count += 1
	print('YES' if odd_count < 2 else 'NO')

if __name__ == '__main__':
	main()
