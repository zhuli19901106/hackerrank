import re

'''
6
1 4 3 5 6 2
'''

def one_insertion(a, n):
	val = a[n - 1]
	i = n - 2
	while i >= 0 and a[i] > val:
		a[i + 1] = a[i]
		i -= 1
	a[i + 1] = val

def main():
	n = int(raw_input())
	a = [int(val) for val in re.split(' ', raw_input())]
	for i in range(2, n + 1):
		one_insertion(a, i)
		print(' '.join([str(val) for val in a]))

if __name__ == '__main__':
	main()
