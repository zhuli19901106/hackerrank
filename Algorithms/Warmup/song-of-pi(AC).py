import re

def main():
	pi = '31415926535897932384626433833'
	pi = [int(val) for val in list(pi)]
	lp = len(pi)
	
	t = int(raw_input())
	for ti in range(t):
		s = raw_input()
		s = [len(val) for val in re.findall('[a-zA-Z]+', s)]
		ls = len(s)
		
		suc = True
		if ls > lp:
			suc = False
		else:
			i = 0
			while i < ls:
				if s[i] != pi[i]:
					suc = False
					break
				i += 1
		if suc:
			print('It\'s a pi song.')
		else:
			print('It\'s not a pi song.')

if __name__ == '__main__':
	main()
