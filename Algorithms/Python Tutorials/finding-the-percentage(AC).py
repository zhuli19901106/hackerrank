import re

def main():
	n = int(raw_input())
	d = {}
	for i in xrange(n):
		name, c = re.split(' ', raw_input(), 1)
		c = map(float, re.split(' ', c))
		d[name] = c[0] + c[1] + c[2]
	name = raw_input()
	print('%.2f' % (d[name] / 3.0))

if __name__ == '__main__':
	main()
