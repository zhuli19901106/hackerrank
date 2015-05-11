import re

'''
7 4
1110100110
'''

def main():
	n, k = re.split(' ', raw_input())
	n = int(n)
	k = int(k)
	a = map(int, list(raw_input()))
	a.reverse()
	a = a[: n]
	k = min(k, n)
	ans = [a[0]]
	
	i = 1
	while i < k:
		ans.append(a[i] ^ a[i - 1])
		i += 1
	while i < n:
		ans.append(a[i] ^ a[i - 1] ^ ans[i - k])
		i += 1
	
	ans = map(str, ans)
	ans.reverse()
	print(''.join(ans))

if __name__ == '__main__':
	main()
