import re

'''
5
2 1 3 1 2
'''

cc = 0

def one_insertion(a, n):
	global cc
	val = a[n - 1]
	i = n - 2
	while i >= 0 and a[i] > val:
		a[i + 1] = a[i]
		cc += 1
		i -= 1
	a[i + 1] = val

def main():
	global cc
	n = int(raw_input())
	a = [int(val) for val in re.split(' ', raw_input())]
	cc = 0
	for i in range(2, n + 1):
		one_insertion(a, i)
	print(cc)

if __name__ == '__main__':
	main()
