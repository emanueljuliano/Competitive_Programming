n = int(input())
t = list(map(int, input().split()))
t.sort()
def area(a, b, c):
	if(a+b<=c or a+c<=b or b+c<=a): return -1
	p = (a+b+c)/2
	return (p*(p-a)*(p-b)*(p-c))**(1/2)

ans = -0.5
#l1 = t[0], l2=t[1], l3=t[2]
for i in range(n-2):
	a = area(t[i], t[i+1], t[i+2])
	if(a>ans):
		ans = a
		l1 = t[i]
		l2 = t[i+1]
		l3 = t[i+2]
print(l1, l2, l3)
