import re

def main():
	a = raw_input()
	b = raw_input()
	la = len(a)
	lb = len(b)
	ans = 0
	for i in xrange(0, la - lb + 1):
		if a[i: i + lb] == b:
			ans += 1
	print(ans)

if __name__ == '__main__':
	main()
