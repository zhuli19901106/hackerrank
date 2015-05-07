import re

'''
20
0 ab
6 cd
0 ef
6 gh
4 ij
0 ab
6 cd
0 ef
6 gh
0 ij
4 that
3 be
0 to
1 be
5 question
1 or
2 not
4 is
2 to
4 the
'''

def main():
	n = int(raw_input())
	c = [[] for i in xrange(0, 100)]
	half = n / 2
	for i in xrange(0, n):
		num, s = re.split(' ', raw_input(), 1)
		num = int(num)
		c[num].append(s if i >= half else '-')
	res = []
	for i in xrange(0, 100):
		res += c[i]
	print(' '.join(res))

if __name__ == '__main__':
	main()
