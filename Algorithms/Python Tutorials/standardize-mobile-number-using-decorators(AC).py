def main():
	n = int(raw_input())
	ans = []
	for i in xrange(n):
		s = raw_input().strip()
		s = s[len(s) - 10: ]
		ans.append('+91 %s %s' % (s[0: 5], s[5: 10]))
	ans.sort()
	print('\n'.join(ans))

if __name__ == '__main__':
	main()
