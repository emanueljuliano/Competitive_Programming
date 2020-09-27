#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int aux[10][10];
void paux(){
	cout << endl;
	for(int i=3;i <8; i++){
		for(int j=3; j<8; j++)
			cout <<aux[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main(){ _
	int n; cin >> n;
	vector<int> v(n);
	for(auto &i: v) {cin >> i;}
	memset(aux, 0, sizeof(aux));
	for(int i=0;i <n; i++){
		for(int j=i+1; j<n; j++){
			aux[v[i]][v[j]]++;
		}	
	}
	for(int i=0;i <10; i++) aux[i][i]=0;
	paux();
	vector<int> ord = {6, 7, 4, 5, 3};
		int ans =0;
		int it = 0;
		for(auto k : ord) cout << k  << " ";
		cout << endl;
		for(int i=0;i <5; i++){
			int soma = 0;
			int id = ord[it];
			for(int i=0;i <10; i++) soma += aux[id][i];
			for(int i=0;i <10; i++) aux[id][i] = 0, aux[i][id]=0;
			cout << "Soma atual " << id << " " <<soma << endl;
			ans += soma;
			paux();
			it++;
		}
		cout << "Final = " << ans << endl;
	
	

	exit(0);
}
