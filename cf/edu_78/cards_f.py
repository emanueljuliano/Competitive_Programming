# https://codeforces.com/contest/1278/problem/F

def inv(a):
	return pow(a, MOD-2, MOD) %MOD

def fat(a):
	ans = 1
	for i in range(1, a+1):
		ans = (ans*i)%MOD
	return ans

MOD = 998244353
n, m, k = map(int, input().split())
p = inv(m)

# O(Burro) O(n2)-> Fórmula da experança = sum(x^k * C(n, x) * p^x * q^(n-x))
'''
resp = 0
q = (1 - p + MOD) % MOD
for x in range(1, n+1):
	resp += pow(x, k, MOD) %MOD * fat(n) %MOD * invfat(n-x) %MOD * invfat(x) %MOD *pow(p, x, MOD) %MOD * pow(q, n-x, MOD) %MOD
'''
# O(menos burro) O(nlog(k)) -> atualiza somatório usando valores ja calculados
if n<=k:
	q = (1 - p + MOD) % MOD
	inv_q = inv(q)
	p_aux = p
	q_aux = pow(q, n-1, MOD)
	fn = n
	resp = n * p%MOD * q_aux%MOD
	resp = resp%MOD

	for i in range(2, n+1):
		x = pow(i, k, MOD)
		p_aux = p_aux * p %MOD
		q_aux = q_aux * inv_q	
		fn = fn*(n-i+1)%MOD*inv(i)%MOD
		
		resp = resp + x * fn %MOD * p_aux %MOD * q_aux %MOD
		resp = resp%MOD
	print(resp)

# O(inteligente) O(k2) -> A partir da FGM M(X), identifica padrão das derivadas
# k-ésima derivada de M(X) = E(x^k)
# E(x^k) = n!/(n-k)! * p^k + k*(deriv[k-1] - sum(ind[i]*deriv[i])) + sum(ind[i]*deriv[i+1])
else:
	deriv = [(n*p)%MOD] #E(x) = np
	resp = n*n%MOD*p%MOD*p%MOD - n*p%MOD*p%MOD + n*p%MOD #E(x^2) = n^2p^2 - np^2 + np
	deriv.append(resp%MOD)
	fn = (n*(n-1))%MOD
	v=[1];
	
	for i in range(3, k+1):
		fn = (fn * (n-i+1) %MOD)%MOD
		w = [(-(i-1)*v[0])%MOD]	
		for j in range(len(v)-1):
			w.append((v[j] - (i-1)*v[j+1]%MOD)%MOD) 
		w.append((v[-1] + i-1)%MOD)
		v = tuple(w)

		resp = (fn * pow(p, i, MOD))%MOD
		for j in range(len(v)):
			resp = (resp + v[j]*deriv[j]%MOD)%MOD	
			resp = resp%MOD
		resp %= MOD
		deriv.append(resp)

	print(deriv[k-1])

