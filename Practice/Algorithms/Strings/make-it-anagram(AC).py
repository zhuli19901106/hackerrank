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
	s1 = raw_input().strip()
	s2 = raw_input().strip()
	d1 = count(s1)
	d2 = count(s2)
	sum = 0
	for val in d1.keys():
		if not val in d2:
			sum += d1[val]
		elif d2[val] < d1[val]:
			sum += d1[val] - d2[val]
	for val in d2.keys():
		if not val in d1:
			sum += d2[val]
		elif d1[val] < d2[val]:
			sum += d2[val] - d1[val]
	print(sum)

if __name__ == '__main__':
	main()
