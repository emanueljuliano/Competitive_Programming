from functools import lru_cache
import sys
sys.setrecursionlimit(int(2e5+10))

MOD = 998244353 

@lru_cache(maxsize=int(2e5 + 10))
def f(k):
	if (k == 1):
		return 10
	if (k == 2):
		return 180
	return (pow(10, k-1, MOD)*9 + 10*f(k-1) - 9*pow(10, k-2, MOD) + 10*MOD)%MOD


n = int(input())

i = n
while (i >= 1):
	print(str(f(i)) + " ", end="")
	i -= 1

