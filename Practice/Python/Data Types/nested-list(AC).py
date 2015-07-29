import re

def main():
	n = int(raw_input())
	a = []
	sc = []
	for i in range(n):
		name = raw_input()
		score = float(raw_input())
		sc.append(score)
		a.append([name,score])
	sc = list(set(sc))
	sc.sort()
	ans = []
	for i in range(n):
		if a[i][1] == sc[1]:
			ans.append(a[i][0])
	ans.sort()
	print('\n'.join(ans))

if __name__ == '__main__':
	main()
