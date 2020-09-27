n= int(input())

t = input().split()

g = {}
for s in t:
    g[s] = []

for i in range(n):
    (a, n) = input().split()
    n = int(n)
    for j in range(n):
        ent = input()
        ent = ent.replace(", ", " ")
        ver = ent.split()
        for v in ver[1:]:
            g[v].append(a)
ans = []
ret = []
def mcic(v):
    ret = []
    pai = {}
    for i in t:
        pai[i] = '-1';
    q = []
    pai[v] = v
    q.append(v)
    achou = False
    a = ''
    b = ''
    while q:
        x = q.pop(0)
        for i in g[x]:
            if(i==v):
                achou = True
                a = x
                break
            if(pai[i]=='-1'):
                pai[i] = x
                q.append(i)
        if(achou):
            break
    if achou:
        ret.append(a)
        aux = pai[a]
        while aux != v:
            ret.append(aux)
            aux = pai[aux]
        if(a != v): ret.append(v)

    return ret 

at = 10000000
for i in t:
    ret = mcic(i)
    #print(ret, i, len(ret), at)
    if(len(ret)!=0 and len(ret)<at):
        ans = []
        for k in ret:
            ans.append(k)
        at = len(ret)

if(len(ans)==0):
    print("SHIP IT")
else:
    for i in ans:
        print(i, end=' ')
    print()
