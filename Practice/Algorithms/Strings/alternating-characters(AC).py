import re

def main():
	t = int(raw_input())
	for ti in xrange(t):
		s = raw_input().strip()
		n = len(s)
		ans = 0
		i = 0
		while i < n:
			j = i + 1
			while j < n and s[i] == s[j]:
				j += 1
			ans += j - i - 1
			i = j
		print(ans)

if __name__ == '__main__':
	main()
