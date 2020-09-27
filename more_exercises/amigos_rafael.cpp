#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	if (a > b) return a;
	else return b;
}

int main(){ 
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int maior = a[0];
	int resposta = 0;
	for (int i = 1; i < n; i++){
		resposta = max(resposta, a[i] + i + maior);
		maior = max(maior, a[i] - i);

		resposta = max(resposta, a[i] - 1);
	}
	printf("%d\n", resposta);
	return 0;
}

