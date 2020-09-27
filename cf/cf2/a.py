q = int(input())

for i in range(q):
	n = int(input())
	s = list(map(int, input().split()))
	s.sort(reverse=True)
	soma = 0
	for i in s:
		if i>2048:
			continue
		if soma + i>2048:
			continue
		else:
			soma+=i
	if soma == 2048:
		print("YES")
	else:
		print("NO")

