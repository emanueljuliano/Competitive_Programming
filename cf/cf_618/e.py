n = int(input())
v = map(int, input().split())
s = 0
soma = [v[0]]
for i in range(1, n):
	soma.append(soma[i-1]+v[i])

for i in range(n-1):
	if v[i]<v[i+1]:
		s+=v[i]
		at = i
		media = s
		while i<n-1 and media, v[i+1]):
			i+=1
			s+=v[i]
			media = soma() 

		for j in range(at, i):
			v[i] = media
		
		
