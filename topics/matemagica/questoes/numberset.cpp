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
const int MAX = 1e6+10;

vector<int> pri;
int sz[MAX], id[MAX];

void crivo(){
	vector<int> p(MAX, 1);

	for(int i=2; i<MAX; i++) if(p[i]){
			pri.pb(i);
			int aux = i;
			while(aux+i<MAX){
				aux+=i; p[aux]=0;
			}
		}
}

void build(ll x){
	for(int i=0; i<=x; i++) id[i]=i, sz[i]=1;
}

int find(int p){
	if(id[p] == p) return p;
	return id[p] = find(id[p]);
}
void une(int p, int q){
	p = find(p), q = find(q);
	if(p==q) return;
	if(sz[p]>sz[q]) swap(p, q);
	id[p] = q;
	sz[q] += sz[p];
}

int main(){ _
	crivo();
	int t; cin >> t;
	int cs = 0;
	while(t--){
		cs++;
		ll a, b, p; cin >> a >> b >> p;
		build(b-a);

		for(int i=0; i<pri.size() and pri[i]<int(b-a); i++){
			ll x = pri[i];
			if(x<p) continue;
			ll mini = (a+x-1)/x;
			ll maxi = b/x;
			for(int j=1; j<= maxi-mini; j++){
				une((mini+j)*x-a, mini*x-a);
			}
		}
		vector<int> mem(b-a+1, 0);
		int ans = 0;
		for(int i=0; i<=(b-a); i++){
			if(!mem[find(i)]) ans++;
			mem[find(i)] = 1;
		}
		cout << "Case #" << cs << ": " << ans << endl;
	}
	
	exit(0);
}
