import xml.etree.ElementTree as ET

attr_count = 0

def dfs(root):
	global attr_count
	attr_count += len(root.attrib)
	for child in root.getchildren():
		dfs(child)

def main():
	global attr_count
	
	n = int(raw_input())
	text = []
	for i in xrange(n):
		s = raw_input().strip()
		text.append(s)
	text = ''.join(text)
	root = ET.fromstring(text)
	attr_count = 0
	dfs(root)
	print(attr_count)

if __name__ == '__main__':
	main()
