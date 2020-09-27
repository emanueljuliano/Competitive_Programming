import numpy as np;
guster = [[0, 2],
			 [5, 1]]

geraldo = [[4, 2],
			  [1, 6]]

"""
[0, 2] [4, 2] = [2, 12]
[5, 1] [1, 6] = [21, 16]
"""
aguarda = 0
eminem = [[0, 0],
			 [0, 0]]

print("eminem é isso daqui, que é igual a guster vezes geraldo, parabens, eminem tem um nome horrível vindo de guster e geraldo.")
for k in range(2):
	for j in range(2):
		for i in range(2):
			aguarda +=  guster[k][i] * geraldo[i][j]
		
		eminem[k][j] = aguarda
#		print(aguarda, end=' ')
		aguarda = 0
#	print()

#print()
print("Olha como eminem é feio:")
#print(np.mat(eminem))
print("'-'")
