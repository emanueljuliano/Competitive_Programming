M = [[0 for col in range(70)] for row in range(70)]
for i in range(64):
	s = input()
	for j in range(len(s)):
		if s[j]!= ' ':
			M[i][j] = 1
print(M)

