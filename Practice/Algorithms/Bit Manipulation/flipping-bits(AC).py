import re

def main():
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		print(~n & 0xffffffff)

if __name__ == '__main__':
	main()