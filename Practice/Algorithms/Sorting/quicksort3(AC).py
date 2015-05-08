import re

'''
7
1 3 9 8 2 7 5
'''

def partition(a, ll, rr):
	if ll >= rr:
		return
	i = j = ll
	p = a[rr]
	while True:
		while i <= rr - 1 and a[i] <= p:
			i += 1
		if i == rr:
			print(' '.join(map(str, a)))
			return i
		j = max(i + 1, j)
		while j <= rr - 1 and a[j] > p:
			j += 1
		a[i], a[j] = a[j], a[i]
		if j == rr:
			print(' '.join(map(str, a)))
			return i

def quick_sort(a, ll, rr):
	if ll >= rr:
		return
	pos = partition(a, ll, rr)
	quick_sort(a, ll, pos - 1)
	quick_sort(a, pos + 1, rr)

def main():
	n = int(raw_input())
	a = map(int, re.split(' ', raw_input()))
	quick_sort(a, 0, len(a) - 1)

if __name__ == '__main__':
	main()
