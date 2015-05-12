import re

def is_funny(s):
	s = [ord(val) for val in list(s)]
	r = s[:]
	r.reverse()
	n = len(s)
	i = 0
	while i < n - 1:
		if abs(s[i + 1] - s[i]) != abs(r[i + 1] - r[i]):
			break
		i += 1
	return i == n - 1

def main():
	t = int(raw_input())
	for ti in xrange(t):
		s = raw_input()
		print('Funny' if is_funny(s) else 'Not Funny')

if __name__ == '__main__':
	main()
