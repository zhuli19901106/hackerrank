import xml.etree.ElementTree as ET

max_depth = 0

def dfs(root, depth):
	global max_depth
	
	max_depth = max(max_depth, depth)
	for child in root.getchildren():
		dfs(child, depth + 1)

def main():
	global max_depth
	
	n = int(raw_input())
	text = []
	for i in xrange(n):
		s = raw_input().strip()
		text.append(s)
	text = ''.join(text)
	root = ET.fromstring(text)
	max_depth = 0
	dfs(root, 0)
	print(max_depth)

if __name__ == '__main__':
	main()
