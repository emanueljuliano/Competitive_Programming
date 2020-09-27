#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int MAX = 150100;
int id[MAX];
vector <int> v[MAX];

int find(int p){
	if(p == id[p]) return p;
	return id[p] = find(id[p]);
}

void uni(int p, int q){
	p = find(p);
	q = find(q);
	if(p==q) return;
	if(v[p].size() > v[q].size()) swap(p, q);

	for(int i: v[p]){
		v[q].pb(i);
		id[i] = q;
	}
	v[p].clear();

	return;
}

int main(){ 
	int n;
	cin >> n;
	for(int i=0; i<=n; i++) id[i] = i, v[i] = {i};

	for(int i=0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		uni(a, b);
	}
int	ans = find(1);
	for(int i=0; i<n; i++){
		cout << v[ans][i] << " ";
	}
	cout << endl;
	exit(0);
}
