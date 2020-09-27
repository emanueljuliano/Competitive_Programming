#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> conjuntos(10100);


int inters(int x, int y){
    int tem1[61] = {0};
    int tem2[61] = {0};
    int quantidade = 0;
    for(int i=0;i<conjuntos[x].size();i++){
        if(tem1[conjuntos[x][i]]==0){
            tem1[conjuntos[x][i]]=1;
        }    
    }
    for(int i=0;i<conjuntos[y].size();i++){
        if(tem1[conjuntos[y][i]]==1){
            if(tem2[conjuntos[y][i]]==0){
                tem2[conjuntos[y][i]]=1;
                quantidade++;
            }
        }    
    }
    return quantidade;
}

int uniao(int x, int y){
    int tem[61] = {0};
    int quantidade=0;
    for(int i=0;i<conjuntos[x].size();i++){
        if(tem[conjuntos[x][i]]==0){
            tem[conjuntos[x][i]]=1;
            quantidade++;
        }    
    }    
    for(int i=0;i<conjuntos[y].size();i++){
        if(tem[conjuntos[y][i]]==0){
            tem[conjuntos[y][i]]=1;
            quantidade++;
        }    
    }    
    return quantidade;
}

int main(){
    int instances; //quantidade de instancias
    scanf("%d",&instances);
    for(int ci=0;ci<instances;ci++){ //ci = current instance
        int qc;
        scanf("%d",&qc);
		for(int x=1; x<=qc; x++) conjuntos[x].resize(0);
        for(int x=1;x<=qc;x++){
            int j;
            scanf("%d",&j);
            for(int i=0;i<j;i++){
                int num;
                scanf("%d",&num);
                conjuntos[x].push_back(num);    
            }    
        }
        int qo; //quantidade de ordens
        scanf("%d",&qo);
        for(int o=0;o<qo;o++){
            int m,x,y;
            scanf("%d %d %d",&m,&x,&y);    
            if(m==1){
                printf("%d\n",inters(x,y));
            }
            else if(m==2){
                printf("%d\n",uniao(x,y));
            }
        }
    }
}
