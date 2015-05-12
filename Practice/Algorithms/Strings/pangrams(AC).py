import re

def main():
	s = re.sub('\W', '', ''.join(list(set(raw_input().strip().lower()))))
	print('pangram' if len(s) == 26 else 'not pangram')

if __name__ == '__main__':
	main()
