import re

def next_permutation(s):
	n = len(s)
	i = n - 2
	while i >= 0 and s[i] >= s[i + 1]:
		i -= 1
	if i == -1:
		return False
	j = i + 1
	while j < n and s[i] < s[j]:
		j += 1
	j -= 1
	s[i], s[j] = s[j], s[i]
	s1 = s[i + 1: ]
	s1.reverse()
	s[i + 1: ] = s1
	return True

def main():
	t = int(raw_input())
	for ti in xrange(t):
		s = list(raw_input().strip())
		if not next_permutation(s):
			print('no answer')
		else:
			print(''.join(s))

if __name__ == '__main__':
	main()
