import math
import re

def mod(a):
	return math.sqrt(a.real ** 2 + a.imag ** 2)

def getval(s):
	x, y = re.split('\s+', s)
	x = float(x)
	y = float(y)
	return x + y * 1j

def printval(a):
	if a.imag == 0:
		print('%.2f' % a.real)
	elif a.real == 0:
		print('%.2fi' % a.imag)
	elif a.imag > 0:
		print('%.2f + %.2fi' % (a.real, abs(a.imag)))
	else:
		print('%.2f - %.2fi' % (a.real, abs(a.imag)))

def main():
	a = getval(raw_input().strip())
	b = getval(raw_input().strip())
	printval(a + b)
	printval(a - b)
	printval(a * b)
	printval(a / b)
	print('%.2f' % mod(a))
	print('%.2f' % mod(b))

if __name__ == '__main__':
	main()
