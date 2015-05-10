import re

def main():
	n = int(raw_input())
	pat = '^[\w-]+@([a-zA-Z0-9]+\.)+[a-zA-Z0-9]{1,3}$'
	ans = []
	for i in xrange(n):
		s = raw_input()
		if re.match(pat, s):
			ans.append(s)
	ans.sort()
	print(ans)

if __name__ == '__main__':
	main()