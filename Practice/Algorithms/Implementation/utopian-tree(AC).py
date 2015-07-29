if __name__ == '__main__':
	ans = [0 for i in range(61)]
	ans[0] = 1
	for i in range(1, 61):
		if i & 1:
			ans[i] = ans[i - 1] * 2
		else:
			ans[i] = ans[i - 1] + 1
	
	s = raw_input()
	t = int(s)
	for ti in range(t):
		try:
			s = raw_input()
		except EOFError:
			break
		n = int(s)
		print(ans[n])
