import re

def main():
	n1 = int(raw_input())
	s1 = set(map(int, re.split(' ', raw_input())))
	n2 = int(raw_input())
	s2 = set(map(int, re.split(' ', raw_input())))
	ans = list((s1 | s2) - (s1 & s2))
	ans.sort()
	print('\n'.join(map(str, ans)))

if __name__ == '__main__':
	main()
