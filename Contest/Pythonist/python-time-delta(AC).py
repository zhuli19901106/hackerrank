import datetime
import re
import time

'''
2
Sun 10 May 2015 13:54:36 -0700
Sun 10 May 2015 13:54:36 +0000
Sat 02 May 2015 19:54:36 +0530
Fri 01 May 2015 13:54:36 +0000
'''

def process(s):
	s1 = s[: -6]
	s2 = s[-5: ]
	stamp = int(time.mktime(time.strptime(s1, '%a %d %b %Y %H:%M:%S')))
	ds = int(s2[1: 3]) * 3600 + int(s2[-2: ]) * 60
	if s2[0] == '-':
		ds = -ds
	return stamp - ds

def main():
	t = int(raw_input())
	for ti in xrange(t):
		s1 = raw_input()
		s2 = raw_input()
		st1 = process(s1)
		st2 = process(s2)
		print(abs(st2 - st1))

if __name__ == '__main__':
	main()