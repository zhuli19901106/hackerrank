import re

def main():
	t = int(raw_input())
	for ti in range(t):
		n, c, m = re.split(' ', raw_input())
		n = int(n)
		c = int(c)
		m = int(m)
		
		n /= c
		ans = n
		while n >= m:
			ans += n / m
			n = n % m + n / m
		print(ans)

if __name__ == '__main__':
	main()
