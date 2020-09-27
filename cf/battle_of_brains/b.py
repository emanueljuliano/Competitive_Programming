from math import pi
t = int(input())

for cs in range(1, t+1):
	a, b = map(int, list(input().split()))
	v = a/b
	r = (3*v/(4*pi))**(1/3)
	ans = 4*pi*r*r
	print(f"Case {cs}: {ans:.4f}")
