# Enter your code here. Read input from STDIN. Print output to STDOUT
#!/usr/bin/py
def lonelyinteger(a):
	answer = 0
	for x in b:
		if(b.count(x)==1):
			#****FILL THE MISSING LINE HERE****
			return x
			break
	return answer
if __name__ == '__main__':
	a = input()
	b = map(int, raw_input().strip().split(" "))
	print lonelyinteger(b)
