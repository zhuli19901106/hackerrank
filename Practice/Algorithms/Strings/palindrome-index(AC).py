import re

def is_palindrome(s):
	n = len(s)
	i = 0
	j = n - 1
	while i < j and s[i] == s[j]:
		i += 1
		j -= 1
	return i >= j

def main():
	t = int(raw_input())
	for ti in xrange(t):
		s = raw_input()
		if is_palindrome(s):
			print(-1)
			continue
		i = 0
		j = len(s) - 1
		while i < j and s[i] == s[j]:
			i += 1
			j -= 1
		if is_palindrome(s[i: j]):
			print(j)
		elif is_palindrome(s[i + 1: j + 1]):
			print(i)

if __name__ == '__main__':
	main()
