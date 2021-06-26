t = input()

t = t.replace('1', '0')
t = t.replace('2', '0')
t = t.replace('3', '0')
t = t.replace('4', '0')
t = t.replace('5', '0')
t = t.replace('6', '0')
t = t.replace('7', '0')
t = t.replace('8', '0')
t = t.replace('9', '0')
t = t.replace('$$$', '0')
t = t.replace('{', '(')
t = t.replace('}', ')')
t = t.replace(':', '*')
t = t.replace('|', '+')

print(t)
try:
	eval(t)
	print("YES")
except:
	print("NO")
