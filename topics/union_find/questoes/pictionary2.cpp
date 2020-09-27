#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int MAX = 1e5+10;

int ti[MAX], id[MAX], sz[MAX];

void build(){
	for(int i=0;i <MAX; i++) ti[i]=-1, sz[i]=1, id[i]=i;
}


int find(int p, int t){
	if(id[p]==p or ti[p]>t) return p;
	return find(id[p], t);
}

void une(int p, int q, int t){
	p = find(p, t), q = find(q, t);
	if(p==q) return;
	if(sz[p]>sz[q]) swap(p, q);
	sz[q] += sz[p];
	id[p] = q;
	ti[p] = t;
}

int main(){ 
	int n, q, m; cin >> n >> m >> q;

	int t = 1;
	build();

	for(int i=m; i; i--){
		for(int j=i; j<=n; j+=i){
			une(i, j, t);
		}
		t++;
	}

	while(q--){
		int a, b; cin >> a >> b;
		int l = 1, r = m;
		while(l<r){
			int mm = (l+r)/2;
			if(find(a, mm) == find(b, mm)) r = mm;
			else l = mm+1;
		}
		cout << l << endl;
	}


	exit(0);
}
