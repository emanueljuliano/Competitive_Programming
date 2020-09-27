#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef pair <double, double> pii;
typedef vector <pii > vpii;

double ans=0;
int id[1100], sz[1100];
vector < pair < double, pair<int, int> > > ar;
vpii v;

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
		int a = ar[i].ss.ff, b=ar[i].ss.ss;
		double p=ar[i].ff;
		if(find(a) != find(b)){
			une(a, b);
			ans = max(ans, p);
		}
	}
	return;
}

int main(){ 
	int n;
	while (true){
	cin >> n;
	if(n==0) break;

	for(int i=0; i<=n; i++) id[i] = i, sz[i] = 1;
	v.clear();
	ar.clear();
	ans = 0;
	
	for(int i=0; i<n; i++){
		double a, b;
		cin >> a >> b;	
		v.pb({a, b});
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			double dist = sqrt((v[i].ff - v[j].ff)*(v[i].ff - v[j].ff)
					 		+ (v[i].ss - v[j].ss)*(v[i].ss - v[j].ss));
			ar.pb({dist, {i, j}});
		}
	}
	
	kruskal();
	cout << fixed << setprecision(4);
	cout << ans << endl;
	}
	exit(0);
}
