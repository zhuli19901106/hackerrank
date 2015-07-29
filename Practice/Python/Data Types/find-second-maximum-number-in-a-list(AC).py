import re

def main():
	n = int(raw_input())
	a = map(int, re.split(' ', raw_input()))
	a = list(set(a))
	n = len(a)
	a1 = max(a[0], a[1])
	a2 = min(a[0], a[1])
	for i in xrange(2, n):
		if a[i] > a1:
			a2 = a1
			a1 = a[i]
		elif a[i] > a2:
			a2 = a[i]
	print(a2)

if __name__ == '__main__':
	main()
