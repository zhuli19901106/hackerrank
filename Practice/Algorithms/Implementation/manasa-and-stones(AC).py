import re

'''
2
3 
1
2
4
10
100
'''

def main():
	t = int(raw_input())
	for ti in range(t):
		n = int(raw_input()) - 1
		a = int(raw_input())
		b = int(raw_input())
		if a > b:
			a, b = b, a
		ans = []
		for i in range(n + 1):
			ans.append((n - i) * a + i * b)
		ans = list(set(ans))
		ans.sort()
		print(' '.join([str(val) for val in ans]))

if __name__ == '__main__':
	main()
