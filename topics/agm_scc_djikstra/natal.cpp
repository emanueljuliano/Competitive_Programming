#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair <int, int> pii;

vector<pair<int, pii>> v;
int id[1100], sz[1100];
int n;
ll peso=0;

int find(int x){
	if(id[x]==x) return x;
	return id[x] = find(id[x]);
}

void une(int p, int q){
	p = find(p);
	q = find(q);
	if (p==q) return;
	if(sz[p] > sz[q]) swap(p, q);
	id[p]=q;
	sz[q]+= sz[p];
	return;
}

void kruskal(){
	peso = 0;
	for(int i=0; i<n; i++)
		id[i]=i, sz[i]=1;
	
	sort(v.begin(), v.end());
	for(int i=0; i<(int)v.size(); i++){
		int a = v[i].ss.ff, b = v[i].ss.ss;
	//	cout << a << " " << b << endl;
		if(find(a)!=find(b)){
			une(a, b);
			peso += v[i].ff;
			//cout << peso << " ";
		}
	}
}

int main(){ 
	int t;
	cin >> t;
	while(t--){
		ll k;
		cin >> n >> k;
		vector<pii > w;
		for(int i=0;i<n; i++){
			int x, y;
			cin >> x >> y;
			w.pb({x, y});
		}

		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				int p;
				int a = abs(w[i].ff - w[j].ff);
				int b = abs(w[i].ss - w[j].ss);
				if(a==0 or b==0) p = max(a, b)-1;
				else if(a==1 or b==1) p = 0;
				else p = __gcd(a, b)-1;
				//cout << p << " ";
				v.pb({p, {i, j}});
			}
		}	
		kruskal();
		cout << peso*k << endl;
		v.resize(0);
	}

	exit(0);
}
