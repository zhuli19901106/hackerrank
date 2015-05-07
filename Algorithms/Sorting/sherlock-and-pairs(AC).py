import re

'''
2
3
1 2 3
3
1 1 2
'''

def main():
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		a = map(int, re.split(' ', raw_input()))
		a.sort()
		ans = 0
		i = 0
		while i < n:
			j = i + 1
			while j < n and a[i] == a[j]:
				j += 1
			ans += (j - i) * (j - i - 1)
			i = j
		print(ans)

if __name__ == '__main__':
	main()
