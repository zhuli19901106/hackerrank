import re

'''
4
5 4 3 2
'''

def main():
	n = int(raw_input())
	a = map(int, re.split(' ', raw_input()))
	a.sort()
	min_diff = a[1] - a[0]
	for i in xrange(1, n - 1):
		min_diff = min(min_diff, a[i + 1] - a[i])
	ans = []
	for i in xrange(1, n):
		if a[i] - a[i - 1] != min_diff:
			continue
		ans.append(a[i - 1])
		ans.append(a[i])
	print(' '.join(map(str, ans)))

if __name__ == '__main__':
	main()
