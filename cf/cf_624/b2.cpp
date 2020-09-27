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

const int MAXP = 110;
int id[MAXP];
int sz[MAXP];

int find(int p){
	if (id[p] == p) return p;
		return id[p] = find(id[p]);
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

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		for(int i=0; i<=100; i++){id[i] = i, sz[i]=1;}
		vector<int> v(n), p(m, 0);
		int a;
		bool ans = true;
		for(int i=0; i<n; i++) {cin >> v[i]; p[v[i]]=1;}
		for(int i=0; i<m; i++) {cin >> a; if(p[a]==1) une(a, a+1);}
		for(int i=1; i<n; i++){
			for(int j=0; j<i; j++){
				if(v[j]>v[i]){
					if(find(v[j])!=find(v[i])) ans = false;
					else 
				}
			}
		}
		if(ans) cout << "YES" << endl;
		else cout <<"NO" << endl;
	}
	
	
	
	exit(0);
}

