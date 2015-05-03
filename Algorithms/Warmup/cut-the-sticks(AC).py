import re

def main():
	n = int(raw_input())
	a = [int(val) for val in re.split(' ', raw_input())]
	a.sort()
	
	i = 0
	while i < n:
		print(n - i)
		j = i + 1
		while j < n and a[j] == a[i]:
			j += 1
		i = j

if __name__ == '__main__':
	main()
