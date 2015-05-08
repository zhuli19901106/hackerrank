import re

if __name__ == '__main__':
	x = int(raw_input())
	y = int(raw_input())
	
	ans = 0
	for i in range(x, y + 1):
		for j in range(x + 1, y + 1):
			ans = max(ans, i ^ j)
	print(ans)
