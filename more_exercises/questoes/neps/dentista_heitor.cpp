#include <iostream>
#define MAXNUM 10100
using namespace std;

struct horario{
	int inicio_,termino_;
};

void merge(horario vetor[],int l,int m,int u){
	int i,j,k,n1,n2;
	n1 = m - l + 1;
	n2 = u - m;

	horario v1[n1];
	horario v2[n2];

	for(i = 0;i < n1;i++)
		v1[i] = vetor[l + i];

	for(j = 0;i < n2;i++)
		v1[i] = vetor[m + i + 1];

	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2){
		if(v1[i].termino_ <= v2[j].termino_){
			vetor[l + k] = v1[i];
			i++;
			k++;
		}else{
			vetor[l + k] = v2[j];
			j++;
			k++;
		}
	}

	while(i < n1){
		vetor[l + k] = v1[i];
		i++;
		k++;
	}

	while(j < n2){
		vetor[l + k] = v2[j];
		j++;
		k++;
	}
}

horario* mergesort(horario vetor[],int l,int u){
	int m = (l + u)/2;
	if(l > m)
		mergesort(vetor,l,m);
	if(u > m + 1)
		mergesort(vetor,m + 1,u);
	merge(vetor,l,m,u);
	return vetor;
}

int main(int argc,char *argv[]){
	int n,n_consultas = 0,ultimo_fim = 0;
	horario horarios[MAXNUM];

	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> horarios[i].inicio_ >> horarios[i].termino_;
	}

	mergesort(horarios,0,n - 1);
	for(int i = 0;i < n;i++){
		if(horarios[i].inicio_ >= ultimo_fim){
			n_consultas++;
			ultimo_fim = horarios[i].termino_;
		}
	}
	cout << n_consultas << endl;

	return 0;
}
