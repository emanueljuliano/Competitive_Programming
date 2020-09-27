#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ss second
#define ff first

typedef pair <int, int> pii;

int id[100], sz[100];
int peso=0;
vector <pair <int, pii> > ar;

int find(int p){
	if(id[p] == p) return p;
	return id[p] = find(id[p]);
}

void une(int p, int q){
	p = find(p);
	q = find(q);
	if(p==q) return;
	if(sz[p]>sz[q]) swap(p, q);

	id[p] = q;
	sz[q] += sz[p];
	return;
}

void kruskal(){
	sort(ar.begin(), ar.end());
	for(int i=0; i<(int)ar.size(); i++){
		int a = ar[i].ss.ff, b = ar[i].ss.ss, p=ar[i].ff;
		if(find(a) != find(b)){
			une(a, b);
			peso += p;
		}
	}
}

int main(){ 
	int r, c;
	cin >>  r >> c;
	for(int i=0; i<=r; i++) id[i] = i, sz[i] = 1;
	for(int i=0; i<c; i++){
		int a, b, p;
		cin >> a >> b >> p;
		ar.pb({p, {a, b}});
	}

	kruskal();
	cout << peso << endl;

	exit(0);
}
