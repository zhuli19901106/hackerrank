import re

'''
7
5 8 1 3 7 9 2
'''

def partition(a, ll, rr):
	if ll >= rr:
		return
	al = []
	ar = []
	p = a[ll]
	for i in xrange(ll + 1, rr + 1):
		if a[i] < p:
			al.append(a[i])
		else:
			ar.append(a[i])
	pos = len(al)
	al.append(p)
	a[ll: rr + 1] = al + ar
	return ll + pos

def quick_sort(a, ll, rr):
	if ll >= rr:
		return
	pos = partition(a, ll, rr)
	quick_sort(a, ll, pos - 1)
	quick_sort(a, pos + 1, rr)
	print(' '.join(map(str, a[ll: rr + 1])))

def main():
	n = int(raw_input())
	a = map(int, re.split(' ', raw_input()))
	quick_sort(a, 0, len(a) - 1)

if __name__ == '__main__':
	main()
