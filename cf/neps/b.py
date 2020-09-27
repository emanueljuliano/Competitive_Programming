n = input()

fib2 = 1
fib1 = 1
flag = False

if(n==1): flag = True
while(fib2<=n):
	aux = fib2
	fib2 = fib1+fib2
	fib1 = aux
	if(fib2==n): flag = True
if(flag):
	print("SIM")
else:
	print("NAO")
