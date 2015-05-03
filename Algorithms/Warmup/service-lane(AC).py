import re

'''
8 5
2 3 1 2 3 2 3 3
0 3
4 6
6 7
3 5
0 7
'''

def main():
	s = raw_input()
	n, t = re.split(' ', s)
	n = int(n)
	t = int(n)
	s = raw_input()
	a = [int(val) for val in re.split(' ', s)]
	for ti in range(t):
		s = raw_input()
		ans = 5
		x, y = re.split(' ', s)
		x = int(x)
		y = int(y)
		for i in range(x, y + 1):
			ans = min(ans, a[i])
		print(ans)

if __name__ == '__main__':
	main()
