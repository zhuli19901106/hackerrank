import re

def main():
	n = int(raw_input())
	a = [int(val) for val in re.split(' ', raw_input())]
	key = a[n - 1]
	i = n - 1
	while True:
		if i == 0 or a[i - 1] <= key:
			a[i] = key
			print(' '.join([str(val) for val in a]))
			break
		else:
			a[i] = a[i - 1]
			i -= 1
			print(' '.join([str(val) for val in a]))

if __name__ == '__main__':
	main()
