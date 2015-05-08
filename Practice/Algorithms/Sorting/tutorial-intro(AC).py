import re

def binary_search(a, key):
	ll = 0
	rr = len(a) - 1
	while ll <= rr:
		mm = (ll + rr) / 2
		if key > a[mm]:
			ll = mm + 1
		elif key < a[mm]:
			rr = mm - 1
		else:
			return mm
	return -1

def main():
	key = int(raw_input())
	n = int(raw_input())
	a = [int(val) for val in re.split(' ', raw_input())]
	print(binary_search(a, key))

if __name__ == '__main__':
	main()
