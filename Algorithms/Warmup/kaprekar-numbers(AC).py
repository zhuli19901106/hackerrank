import re

def check(n):
	d = len(str(n))
	n2 = str(n * n)
	p1 = n2[: len(n2) - d]
	p1 = 0 if p1 == '' else int(p1)
	p2 = int(n2[len(n2) - d: ])
	return p1 + p2 == n

def main():
	N = 100000
	a = [0 for i in range(N + 1)]
	for i in range(0, N + 1):
		a[i] = check(i)
	p = int(raw_input())
	q = int(raw_input())
	ans = []
	for i in range(p, q + 1):
		if a[i]:
			ans.append(str(i))
	if len(ans) == 0:
		print('INVALID RANGE')
	else:
		print(' '.join(ans))

if __name__ == '__main__':
	main()
