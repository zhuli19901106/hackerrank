import re

def main():
	fib = set([0, 1])
	n1 = 0
	n2 = 1
	while True:
		n3 = n1 + n2
		if n3 > 10000000000:
			break
		else:
			fib.add(n3)
		n1 = n2
		n2 = n3
	
	t = int(raw_input())
	for ti in range(t):
		n = int(raw_input())
		print('IsFibo' if n in fib else 'IsNotFibo')

if __name__ == '__main__':
	main()
