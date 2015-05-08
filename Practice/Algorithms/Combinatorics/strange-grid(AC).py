import re

def main():
	r, c = re.split(' ', raw_input())
	r = int(r) - 1
	c = int(c) - 1
	sum = r / 2 * 2 * 5 + c * 2 + r % 2
	print(sum)

if __name__ == '__main__':
	main()
