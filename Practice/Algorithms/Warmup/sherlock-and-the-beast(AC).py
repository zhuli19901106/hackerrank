import re

def main():
	t = int(raw_input())
	for ti in range(t):
		n = int(raw_input())
		x = n / 3 * 3
		while x >= 0:
			y = n - x
			if y % 5 == 0:
				print(''.join(['5' for val in range(x)]) + ''.join(['3' for val in range(y)]))
				break
			x -= 3
		if x < 0:
			print('-1')

if __name__ == '__main__':
	main()
