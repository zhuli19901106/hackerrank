import re

'''
6
1 4 3 5 6 2
'''

def insertion_sort(l):
	for i in xrange(1, len(l)):
		j = i - 1
		key = l[i]
		while (j >= 0) and (l[j] > key):
			l[j + 1] = l[j]
			j -= 1
		l[j + 1] = key

if __name__ == '__main__':
	m = input()
	ar = [int(val) for val in re.split(' ', raw_input())]
	insertion_sort(ar)
	print(' '.join(map(str, ar)))
