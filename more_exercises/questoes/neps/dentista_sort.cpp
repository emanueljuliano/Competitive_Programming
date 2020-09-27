#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

bool ordena(pii a, pii b){
	return a.second <= b.second;
}

int main(){
	int n, n_consultas=0, a, b, ult_fim = -1;
	vector <pair <int, int> > horarios;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> a >> b;
		horarios.push_back({a, b});
	}
	
	sort(horarios.begin(), horarios.end(), ordena);

	for(int i=0; i<n; i++){
		if(horarios[i].first >= ult_fim){
			n_consultas++;
			ult_fim = horarios[i].second;
		}
	}	

	cout << n_consultas << endl;

	exit(0);
}
