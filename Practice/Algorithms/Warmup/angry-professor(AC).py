import re

def main():
	t = int(raw_input())
	for ti in range(t):
		n, k = re.split(' ', raw_input())
		n = int(n)
		k = int(k)
		a = [int(val) for val in re.split(' ', raw_input())]
		for i in range(n):
			if a[i] <= 0:
				k -= 1
		print('YES' if k > 0 else 'NO')

if __name__ == '__main__':
	main()
