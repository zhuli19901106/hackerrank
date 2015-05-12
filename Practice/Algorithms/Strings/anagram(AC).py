import re

def count(s):
	d = {}
	for val in s:
		if val in d:
			d[val] += 1
		else:
			d[val] = 1
	return d

def main():
	t = int(raw_input())
	for ti in xrange(t):
		s = raw_input().strip()
		n = len(s)
		if n & 1:
			print(-1)
			continue
		n >>= 1
		s1 = s[: n]
		s2 = s[n: ]
		d1 = count(s1)
		d2 = count(s2)
		sum = 0
		for val in d1.keys():
			if not val in d2:
				continue
			d1[val] -= min(d1[val], d2[val])
		for val in d1.keys():
			sum += d1[val]
		print(sum)

if __name__ == '__main__':
	main()
