MOD = 998244353
MAXK = 50

def inv(k):
 return pow(k, MOD-2, MOD)


(n, m, k) = [int(x) for x in input().split(' ')]
p = inv(m)


memo_w = MAXK*[-1]
def w(k):
 if k == 0:
  return 1
 if memo_w[k] != -1:
  return memo_w[k]

 ans = w(k-1)
 ans = (ans*(n-k+1)*p) % MOD
 memo_w[k] = ans
 return ans

memo_coef = MAXK*[MAXK*[-1]]
memo_coef2 = [MAXK*[-1] for _ in range(MAXK)]

print(type(memo_coef), type(memo_coef2), memo_coef==memo_coef2)

def coef(i, k):
 if i <= 0:
  return 0
 if i == k:
  return 1
 if memo_coef[i][k] != -1:
  return memo_coef[i][k]
 ans = (i*coef(i, k-1) + coef(i-1, k-1))%MOD
 memo_coef[i][k] = ans
 return ans

 
anss = 0
for i in range(1, k+1):
 anss = (anss+coef(i, k)*w(i)) % MOD

#print(memo_coef)
print(anss)

