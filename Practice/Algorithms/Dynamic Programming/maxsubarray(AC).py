import re

def max_array_sum(a):
	s1 = max(a)
	if s1 <= 0:
		return s1, s1
		
	n = len(a)
	sum = 0
	s1 = s2 = 0
	for i in range(0, n):
		if a[i] > 0:
			s2 += a[i]
		sum += a[i]
		if sum > s1:
			s1 = sum
		if sum < 0:
			sum = 0
	return s1, s2

def main():
	t = int(raw_input())
	for ti in range(t):
		n = int(raw_input())
		a = [int(val) for val in re.split(' ', raw_input())]
		s1, s2 = max_array_sum(a)
		print('%d %d' % (s1, s2))

if __name__ == '__main__':
	main()
