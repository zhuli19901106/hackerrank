import re

def main():
	x = int(raw_input()) + 1
	y = int(raw_input()) + 1
	z = int(raw_input()) + 1
	n = int(raw_input())
	ans = []
	for xyz in xrange(x * y * z):
		k = xyz % z
		xyz /= z
		j = xyz % y
		xyz /= y
		i = xyz
		if i + j + k == n:
			continue
		ans.append('[%d, %d, %d]' % (i, j, k))
	print('[' + (', '.join(ans)) + ']')

if __name__ == '__main__':
	main()
