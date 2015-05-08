import re

def main():
	p = r'^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$'
	s = raw_input()
	print(re.match(p, s) != None)

if __name__ == '__main__':
	main()
