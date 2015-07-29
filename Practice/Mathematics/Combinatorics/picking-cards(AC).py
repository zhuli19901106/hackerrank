import re

def main():
	mod = 1000000007
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		a = map(int, re.split(' ', raw_input()))
		c = [0 for i in xrange(n)]
		suc = True
		for i in xrange(n):
			if a[i] == n:
				suc = False
				break
			else:
				c[a[i]] += 1
		if not suc:
			print(0)
			continue
		ans = c[0]
		for i in xrange(1, n):
			c[i] += c[i - 1] - 1
			if c[i] == 0:
				suc = False
				ans = 0
				break
			else:
				ans = ans * c[i] % mod
		print(ans)

if __name__ == '__main__':
	main()
