n = int(input())

for i in range(n):
	s = input()
	s = list(s)
	if len(set(s)) < len(s):
		print("No")
		continue
	s.sort()
	atual = s[0]
	flag = False
	for c in s[1:]:
		if ord(atual)!=ord(c)-1:
			print("No")
			flag = True
			break
		atual = c
	if flag:
		continue
	print("Yes")



