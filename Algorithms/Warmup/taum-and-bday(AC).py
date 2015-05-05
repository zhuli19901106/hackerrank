import re

'''
5
10 10
1 1 1
5 9
2 3 4
3 6
9 1 1
7 7
4 2 1
3 3
1 9 2
'''

def main():
	t = int(raw_input())
	for ti in range(t):
		b, w = re.split(' ', raw_input())
		b = int(b)
		w = int(w)
		x, y, z = re.split(' ', raw_input())
		x = int(x)
		y = int(y)
		z = int(z)
		p1 = x * b + y * w;
		p2 = (b + w) * x + w * z;
		p3 = (b + w) * y + b * z;
		print(min(p1, p2, p3))

if __name__ == '__main__':
	main()
