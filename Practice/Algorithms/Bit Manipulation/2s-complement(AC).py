import re

def solve(n):
	if n <= 1:
		return n
	i = 0
	while (1 << (i + 1)) <= n:
		i += 1
	return i * (1 << i - 1) + ((n ^ (1 << i)) + 1) + solve(n ^ (1 << i))

def count(a, b):
	if a < 0:
		if b < 0:
			return (b - a + 1) * 32 - count(-b - 1, -a - 1)
		elif b == 0:
			return count(a, -1)
		else:
			return count(a, -1) + count(1, b)
	elif a > 0:
		return solve(b) - solve(a - 1)
	else:
		return solve(b)

def main():
	t = int(raw_input())
	for ti in xrange(t):
		a, b = re.split(' ', raw_input())
		a = int(a)
		b = int(b)
		print(count(a, b))

if __name__ == '__main__':
	main()
