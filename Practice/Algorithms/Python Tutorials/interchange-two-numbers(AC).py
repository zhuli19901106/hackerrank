import re

def main():
	x = int(raw_input())
	y = int(raw_input())
	x, y = y, x
	print(x)
	print(y)

if __name__ == '__main__':
	main()
