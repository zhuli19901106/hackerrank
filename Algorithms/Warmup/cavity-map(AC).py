import re

'''
4
1112
1912
1892
1234
'''

def main():
	a = []
	d = [[-1, 0], [+1, 0], [0, -1], [0, +1]]
	
	n = int(raw_input())
	for i in range(n):
		a.append([int(val) for val in list(raw_input())])
	for i in range(1, n - 1):
		for j in range(1, n - 1):
			k = 0
			while k < 4:
				ii = i + d[k][0]
				jj = j + d[k][1]
				if abs(a[ii][jj]) >= abs(a[i][j]):
					break
				k += 1
			if k == 4:
				a[i][j] = -a[i][j]
	for i in range(n):
		for j in range(n):
			if a[i][j] >= 0:
				a[i][j] = str(a[i][j])
			else:
				a[i][j] = 'X'
		print(''.join(a[i]))

if __name__ == '__main__':
	main()
