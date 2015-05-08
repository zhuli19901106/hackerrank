import re

def gcd(x, y):
	while True:
		if x < y:
			if x == 0:
				return y
			else:
				y %= x
		elif x > y:
			if y == 0:
				return x
			else:
				x %= y
		else:
			return x

def main():
	t = int(raw_input())
	for ti in range(t):
		n = int(raw_input())
		a = [int(val) for val in re.split(' ', raw_input())]
		ans = a[0]
		for i in range(1, n):
			ans = gcd(ans, a[i])
			if ans == 1:
				break
		print('YES' if ans == 1 else 'NO')

if __name__ == '__main__':
	main()
