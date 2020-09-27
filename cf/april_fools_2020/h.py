n = int(input())
at = n//1000
mod = n- at*1000

ans = 1
i = at
while(i>0):
	ans = ans*i;
	ans = ans%mod;
	i-=2
print(ans)
