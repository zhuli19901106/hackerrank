import re

'''
5
4 5 3 7 2
'''

def partition(a, ll, rr):
	p = a[ll]
	i = ll + 1
	j = rr
	while True:
		while i <= rr and a[i] <= p:
			i += 1
		while j >= ll + 1 and a[j] >= p:
			j -= 1
		if i > j:
			a[ll], a[j] = a[j], a[ll]
			break
		else:
			a[i], a[j] = a[j], a[i]

def main():
	n = int(raw_input())
	a = map(int, re.split(' ', raw_input()))
	partition(a, 0, len(a) - 1)
	print(' '.join(map(str, a)))

if __name__ == '__main__':
	main()
