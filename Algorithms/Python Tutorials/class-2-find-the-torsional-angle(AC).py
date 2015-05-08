import math
import re

def getval(s):
	return map(float, re.split(' ', s))

def minus(a, b):
	return [b[i] - a[i] for i in xrange(len(a))]

def vector_product(x, y):
	z = [0, 0, 0]
	z[0] = x[1] * y[2] - x[2] * y[1]
	z[1] = x[2] * y[0] - x[0] * y[2]
	z[2] = x[0] * y[1] - x[1] * y[0]
	return z

def inner_product(x, y):
	ans = 0
	for i in xrange(len(x)):
		ans += x[i] * y[i]
	return ans

def mod(x):
	ans = 0
	for i in xrange(len(x)):
		ans += x[i] ** 2
	return math.sqrt(ans)

def main():
	a = getval(raw_input().strip())
	b = getval(raw_input().strip())
	c = getval(raw_input().strip())
	d = getval(raw_input().strip())
	
	ab = minus(a, b)
	bc = minus(b, c)
	cd = minus(c, d)
	v1 = vector_product(ab, bc)
	v2 = vector_product(bc, cd)
	cs = math.acos(inner_product(v1, v2) / (mod(v1) * mod(v2)))
	cs = cs * 180 / math.pi
	print('%.2f' % cs)

if __name__ == '__main__':
	main()
