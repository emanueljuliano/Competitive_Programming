"""A gente quer saber o valor explicito de (x + y)^-3 + x^-3 sem ter q efetivamente fazer a subtração, pq isso vai dar erro por razões de epsilon da máquina. Então a gente quer representar ele como a soma de números pequenos e não como subtração de números grandes

então vamos fazer assim, representa o primeiro termo como a+b e o segundo como a, então a gente quer saber a+b-a = b

a gente sabe que (a+b)³ = x + y e que a³ = x
logo:
    (a+b)³ = a³ + 3a²b + 3ab² + b³ = x + y
    x + 3*x^(2/3)*b + 3*x^(1/3)*b² + b³ = x + y
    3*x^(2/3)*b + 3*x^(1/3)*b² + b³ = 10^-15 
    // b é muito pequeno então só o primeiro termo importa
    3*x^(2/3)*b = 10^-15
    b = 10^-15/(3*x^(2/3))
"""

while True:
    (l, r) = map(int, input().split())
    if l==0 and r==0:
        break
    ans = 0.0
    for i in range(l, r+1):
        ans += 1/(i)**(2/3)
    ans /= 3.0
    print(f"{ans:.5f}E-15")




