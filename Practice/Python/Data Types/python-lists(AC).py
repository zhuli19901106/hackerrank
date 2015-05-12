import re

n = int(raw_input().strip())
b = []
for i in xrange(n):
	a = re.split(' ', raw_input().strip())
	if a[0] == 'insert':
		b.insert(int(a[1]), int(a[2]))
	elif a[0] == 'remove':
		b.remove(int(a[1]))
	elif a[0] == 'append':
		b.append(int(a[1]))
	elif a[0] == 'pop':
		b.pop()
	elif a[0] == 'sort':
		b.sort()
	elif a[0] == 'reverse':
		b.reverse()
	elif a[0] == 'print':
		print('[' + (', '.join(map(str, b))) + ']')
