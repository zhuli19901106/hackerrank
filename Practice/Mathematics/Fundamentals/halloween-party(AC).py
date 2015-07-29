import re

def main():
	t = int(raw_input())
	for ti in range(t):
		k = int(raw_input())
		print(k / 2 * (k - k / 2))

if __name__ == '__main__':
	main()
