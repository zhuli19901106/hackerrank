import re

def main():
	n = int(raw_input())
	a = [int(val) for val in re.split('\s+', raw_input())]
	sum = 0
	for i in range(n):
		sum ^= a[i];
	print(sum)

if __name__ == '__main__':
	main()
