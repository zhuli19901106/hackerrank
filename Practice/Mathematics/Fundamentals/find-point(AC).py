import re

if __name__ == '__main__':
    t = int(raw_input().strip())
    for ti in xrange(t):
        a, b, c, d = map(int, re.split('\s+', raw_input().strip()))
        print('%d %d' % (2 * c - a, 2 * d - b))
        