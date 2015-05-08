import re

def main():
	a = [0, 1]
	for i in xrange(2, 15):
		a.append(a[i - 2] + a[i - 1])
	a = [pow(val, 3) for val in a]
	n = int(raw_input())
	print(a[: n])

if __name__ == '__main__':
	main()
