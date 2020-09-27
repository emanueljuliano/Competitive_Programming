t = int(input())
b = bin(t+64)
b = b[2:]
ans = ['0', '0', '0', '0', '0', '0']
ans[0] = b[1]
ans[1] = b[6]
ans[2] = b[4]
ans[3] = b[3]
ans[4] = b[5]
ans[5] = b[2]
s = ""
for i in ans:
	s+=i

print(int(s, 2))

