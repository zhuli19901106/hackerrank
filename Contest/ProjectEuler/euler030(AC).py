#https://www.hackerrank.com/contests/projecteuler/challenges/euler030
#http://en.wikipedia.org/wiki/Narcissistic_number
import re
'''
def test(ans, n, m1, m2):
	for i in xrange(m1, m2):
		s = sum([val ** n for val in map(int, list(str(i)))])
		if s == i:
			ans[n].add(sum)
			print(i)
'''
def main():
	ans = {3: set([153, 370, 371, 407]), 4: set([1634, 8208, 9474]), 5: set([4150, 4151, 54748, 92727, 93084, 194979]), 6: set([548834])}
	n = int(raw_input())
	print(sum(ans[n]))

if __name__ == '__main__':
	main()
