part = [0]*int(5e5+5)

def partition(n):
	p = [];
	for i in range(1, int(n**(1/2))+1):
		p.append(int(i*(3*i - 1)/2))
		p.append(int(i*(3*i + 1)/2))
	part[0] = 1
	for i in range(1, n+1):
		j = 0
		while p[j]<=i:
			if j%4 < 2: part[i] += part[i-p[j]]
			else: part[i] -= part[i-p[j]]
			j+=1
n = int(5e5)
MOD = int(1e9)+7
partition(n)
for i in range(0, n+1):
	print(part[i]%MOD, end=' ')
print()	
