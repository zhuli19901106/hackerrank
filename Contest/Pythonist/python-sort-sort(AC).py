import re

k = 0

def cmp(x, y):
	global k
	
	if x[k] > y[k]:
		return 1
	if x[k] < y[k]:
		return -1
	return 0

def main():
	global k
	
	n, m = re.split(' ', raw_input())
	n = int(n)
	m = int(m)
	a = []
	for i in xrange(n):
		a.append(map(int, re.split(' ', raw_input())))
	k = int(raw_input())
	a = sorted(a, cmp)
	print('\n'.join([' '.join(map(str, val)) for val in a]))

if __name__ == '__main__':
	main()
