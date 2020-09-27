#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef pair<int, int> pii;

const int MAX = 50500;
pii id[MAX];
int sz[MAX];

pii find(int p, int v){ // sem otimização da merda
	if(p==id[p].ff) return {p, v};
	return find(id[p].ff, (v+id[p].ss)%3);
}

void une(int p, int q, int v){
	int	a = find(p, 0).ss;
	int b = find(q, 0).ss;
	p = find(p, 0).ff;
	q = find(q, 0).ff;
	if(p==q) return;
	if(sz[p]>sz[q]){
		swap(p, q);
		swap(a, b);
		v = (3-v)%3;
	}
	int c = (3-a+b+v)%3;
	id[p] = {q, c};
	sz[q] += sz[p];
	return;
}


int main(){ 
	int t;
	cin >> t;
	while(t--){
		int ans = 0;
		int n, k;
		cin >> n >> k;

		for(int i=0; i<=n; i++)
			id[i]={i, 0}, sz[i]=1;

		for(int i=0; i<k; i++){
			int d, x, y;
			cin >> d>> x >> y;
			if(x>n || y>n){ ans++; continue;}
			pii p, q;
			p = find(x, 0);
			q = find(y, 0);
	
			if(d==1){
				if(p.ff!=q.ff or p.ss==q.ss)
					une(x, y, 0);
				else
					ans++;
			}
			if (d==2){
				if(p.ff!=q.ff or (p.ss+3-q.ss)%3==1)
					une(x, y, 1);
				else
					ans++;
			}
			p = find(x, 0);
			q = find(y, 0);
		}
		cout << ans << endl;
	}
	exit(0);
}
