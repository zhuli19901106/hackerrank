import re

def main():
	n = int(raw_input())
	k = int(raw_input())
	a = []
	for i in range(n):
		a.append(int(raw_input()))
	a.sort()
	ans = a[k - 1] - a[0]
	for i in range(1, n - k + 1):
		ans = min(ans, a[i + k - 1] - a[i])
	print(ans)

if __name__ == '__main__':
	main()
