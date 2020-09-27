a = input()
a = int(a)

s = input()

mapi = input().split()

t = []
flag = False
c = 0
for i in range(a):
	if(s[i]<mapi[int(s[i])-1]):
		print(mapi[int(s[i])-1], end="")
		flag = True
	elif(s[i]==mapi[int(s[i])-1]):
		print(s[i], end="")
	elif(flag):
		break
	else:
		print(s[i], end="")
	c+=1
for i in range(c, a):
	print(s[i], end="")
print()
