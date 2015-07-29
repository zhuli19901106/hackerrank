import re

def process(s, i):
	s = re.split(' ', s.strip())
	a = []
	a.append('%s %s %s' % (('Mr.' if s[3] == 'M' else 'Ms.'), s[0], s[1]))
	a.append(int(s[2]))
	a.append(i)
	return a

def comp(x, y):
	if x[1] > y[1]:
		return 1
	if x[1] < y[1]:
		return -1
	if x[2] > y[2]:
		return 1
	if x[2] < y[2]:
		return -1
	return 0

def main():
	n = int(raw_input())
	a = []
	for i in xrange(n):
		a.append(process(raw_input(), i))
	a = sorted(a, comp)
	for i in xrange(n):
		print(a[i][0])

if __name__ == '__main__':
	main()
