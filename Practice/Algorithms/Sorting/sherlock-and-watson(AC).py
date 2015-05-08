import re

'''
3 2 3
1 2 3
0
1
2
'''

def main():
	n, k, q = re.split(' ', raw_input())
	n = int(n)
	k = int(k)
	q = int(q)
	a = map(int, re.split(' ', raw_input()))
	for i in range(q):
		idx = int(raw_input())
		print(a[(idx + n - k) % n])

if __name__ == '__main__':
	main()
