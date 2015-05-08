import re

def main():
	a = float(raw_input())
	b = float(raw_input())
	print('%.2f' % (a + b))
	print('%.2f' % (a - b))
	print('%.2f' % (a * b))
	print('%.2f' % (a / b))
	print('%.2f' % (a // b))

if __name__ == '__main__':
	main()
