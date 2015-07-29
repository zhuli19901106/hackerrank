import re

s = 0
ans = 0
n = 0

def dfs(idx, item, tleng):
	global s
	global ans
	global n
	
	if len(item) == tleng:
		ans.add(''.join(item))
		return
	for i in xrange(idx, n - (tleng - len(item)) + 1):
		item.append(s[i])
		dfs(i + 1, item, tleng)
		item.pop()

def main():
	global s
	global ans
	global n
	
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		s = list(raw_input())
		s.sort()
		ans = set()
		item = []
		for i in xrange(1, n + 1):
			dfs(0, item, i)
		ans = list(ans)
		ans.sort()
		print('\n'.join(ans))

if __name__ == '__main__':
	main()
