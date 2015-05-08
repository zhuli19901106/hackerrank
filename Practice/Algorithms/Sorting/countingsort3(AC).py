import re

'''
10
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
	c = [0 for i in xrange(0, 100)]
	for i in xrange(0, n):
		c[int(re.split(' ', raw_input(), 1)[0])] += 1
	for i in xrange(1, 100):
		c[i] += c[i - 1]
	print(' '.join(map(str, c)))

if __name__ == '__main__':
	main()
