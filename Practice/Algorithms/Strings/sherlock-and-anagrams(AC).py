import re

def count(a):
	n = len(a)
	i = 0
	sum = 0
	while i < n:
		j = i + 1
		while j < n and a[i] == a[j]:
			j += 1
		sum += (j - i) * (j - i - 1) / 2
		i = j
	return sum

def main():
	t = int(raw_input())
	for ti in xrange(t):
		s = list(raw_input())
		n = len(s)
		sum = 0
		for i in xrange(1, n):
			a = []
			for j in xrange(0, n + 1 - i):
				a.append(sorted(s[j: j + i]))
			a.sort()
			sum += count(a)
		print(sum)

if __name__ == '__main__':
	main()
