import re

'''
7
1 3 9 8 2 7 5
'''

cc_insert = 0
cc_quick = 0

def insertion_sort(a):
	global cc_insert
	
	n = len(a)
	for i in xrange(1, n):
		val = a[i]
		j = i - 1
		while j >= 0 and a[j] > val:
			a[j + 1] = a[j]
			cc_insert += 1
			j -= 1
		a[j + 1] = val

def partition(a, ll, rr):
	global cc_quick
	
	if ll >= rr:
		return
	p = a[rr]
	for i in xrange(ll, rr + 1):
		if a[i] <= p:
			cc_quick += 1
	i = j = ll
	while True:
		while i <= rr - 1 and a[i] <= p:
			i += 1
		if i == rr:
			return i
		j = max(i + 1, j)
		while j <= rr - 1 and a[j] > p:
			j += 1
		a[i], a[j] = a[j], a[i]
		if j == rr:
			return i

def quick_sort(a):
	qsort(a, 0, len(a) - 1)

def qsort(a, ll, rr):
	if ll >= rr:
		return
	pos = partition(a, ll, rr)
	qsort(a, ll, pos - 1)
	qsort(a, pos + 1, rr)

def main():
	global cc_quick
	global cc_insert
	
	n = int(raw_input())
	a = map(int, re.split(' ', raw_input()))
	b = a[:]
	cc_quick = 0
	quick_sort(a)
	cc_insert = 0
	insertion_sort(b)
	print(cc_insert - cc_quick)

if __name__ == '__main__':
	main()
