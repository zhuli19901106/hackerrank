import re

'''
5 3
1 2 100
2 5 100
3 4 100
'''

def main():
	n, m = re.split(' ', raw_input())
	n = int(n)
	m = int(m)
	sum = 0
	for i in range(m):
		a, b, k = re.split(' ', raw_input())
		a = int(a)
		b = int(b)
		k = int(k)
		sum += (b - a + 1) * k
	print(sum / n)

if __name__ == '__main__':
	main()
