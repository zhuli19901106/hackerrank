import re

pat = ''

def format(a):
	global pat
	
	return [pat % val for val in a]

def main():
	global pat
	
	n = int(raw_input())
	w = len(bin(n)) - 2
	pat = '%%%ds' % w
	a = []
	for i in xrange(1, n + 1):
		a.append([str(i), oct(i)[1: ], hex(i).upper()[2: ], bin(i)[2: ]])
	a = map(format, a)
	print('\n'.join([' '.join(val) for val in a]))

if __name__ == '__main__':
	main()
