#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int respostas_certas[10] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2};
	int respostas_aluno[10], acertos[10], contador;

	for (int i=1; i<=10; i++){
		contador = 0;
		printf("\nDigite as respostas do aluno %d \n", i);
		
		for(int j=0; j<10; j++){
			printf("resposta da questao %d: \n", j+1);
			scanf("%d", &respostas_aluno[j]);	
		}
		printf("\n");
		for(int j=0; j<10; j++){
			if(respostas_aluno[j]==respostas_certas[j]){
				contador++;
				printf("%d > certa \n", j+1);
			}
			else
				printf("%d > errada \n", j+1);
		}
		printf("\n");
		printf("O aluno %d teve %d acertos e %d erros \n \n", i, contador, 10-contador);
	}
	


	return 0;
}
