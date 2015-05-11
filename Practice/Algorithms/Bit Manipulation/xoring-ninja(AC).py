import re

def modpow(x, y, mod):
	if y == 0:
		return 0 % mod
	if y == 1:
		return x % mod
	xx = modpow(x, y >> 1, mod)
	return xx * xx * x % mod if y & 1 else xx * xx % mod

def main():
	mod = 10 ** 9 + 7
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		a = map(int, re.split(' ', raw_input()))
		ans = 0
		for i in xrange(n):
			ans |= a[i]
		ans = ans * modpow(2, n - 1, mod) % mod
		print(ans)

if __name__ == '__main__':
	main()
