import re

def main():
	num = {}
	num[1] = 'one'
	num[2] = 'two'
	num[3] = 'three'
	num[4] = 'four'
	num[5] = 'five'
	num[6] = 'six'
	num[7] = 'seven'
	num[8] = 'eight'
	num[9] = 'nine'
	num[10] = 'ten'
	num[11] = 'eleven'
	num[12] = 'twelve'
	num[13] = 'thirteen'
	num[14] = 'fourteen'
	num[16] = 'sixteen'
	num[17] = 'seventeen'
	num[18] = 'eighteen'
	num[19] = 'nineteen'
	num[20] = 'twenty'
	num[21] = 'twenty one'
	num[22] = 'twenty two'
	num[23] = 'twenty three'
	num[24] = 'twenty four'
	num[25] = 'twenty five'
	num[26] = 'twenty six'
	num[27] = 'twenty seven'
	num[28] = 'twenty eight'
	num[29] = 'twenty nine'

	h = int(raw_input())
	m = int(raw_input())
	
	if m == 0:
		print('%s o\'clock' % num[h])
	elif m == 1:
		print('%s minute past %s' % (num[m], num[h]))
	elif m == 15:
		print('quarter past %s' % num[h])
	elif m == 30:
		print('half past %s' % num[h])
	elif m == 45:
		print('quarter to %s' % num[h + 1])
	elif m == 59:
		print('%s minute to %s' % (num[60 - m], num[h + 1]))
	elif (m > 1 and m < 15) or (m > 15 and m < 30):
		print('%s minutes past %s' % (num[m], num[h]))
	else:
		print('%s minutes to %s' % (num[60 - m], num[h + 1]))

if __name__ == '__main__':
	main()
