#include <iostream>

int main(){

	int v[100000], i=0, contagens=0, aux;
	printf("Digite quantos valores quiser, -1 para parar \n");
	scanf("%d", &aux)
	while(aux!=-1){
		v[i] = aux;
		i++;
		
		scanf("%d", &aux);
	}

	printf("Foram inseridos %d números\n", i);

	int pares=0, impares=0;
	for(int j=0; j<i; j++){
		contagens++;
		if(v[j]%2==0)
			pares++;
		else
			impares++;
	}
	printf("Existem %d números pares e %d números ímpares \n", pares, impares);

	double porc_pares = pares/double(i);
	double porc_impares = impares/double(i);
	printf("A porcentagem de pares é %d  e a porcentagem de ímpares é %d \n", porc_pares, porc_impares);

	int zeros = 0;
	for(int j=0; j<i; j++){
		contagens++;
		if(v[j]==0)
			zeros++;
	}

	printf("%d números zeros apareceram \n", zeros);

	int maior = -1, menor = 1000000;
	for(int j=0; j<i; j++){
		contagens+=2;
		maior = max(v[j], maior);
		menor = min(v[j], menor);
	}

	printf("O maior número é %d e o menor número é %d \n", maior, menor);
	
	printf("Houveram %d contagens \n", contagens)

	return 0;
}
