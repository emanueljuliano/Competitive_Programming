from fractions import Fraction as f
from sys import stdin

for s in stdin:
	ret = []
	prev = '+'
	for c in s:
		if '0' <= c <= '9':
			if not ('0' <= prev <= '9' or prev == '/'): 
				ret.append('f(')
			ret.append(c)
		elif c == '/':
			ret.append(',')
		elif '0' <= prev <= '9':
			ret.append( ')')
			ret.append(c)
		elif c == '(' or c == ')' or c == '+' or c == '-':
			ret.append(c)
		else:
			continue
		prev = c

	if '0' <= prev <= '9':
		ret.append(')')
	
	ans = eval(''.join(ret))
	if ans.denominator == 1:
		print(f'{ans}/1')
	else:
		print(ans)

