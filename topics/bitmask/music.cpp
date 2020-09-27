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

vector<pair<ii, ii>> v;
int n, it = 0;
int pd[2200][1100];
struct show{
	int l, r, o;
};
bool ord(show a, show b){
	if(a.l != b.l) return a.l < b.l;
	if(a.r != b.r) return a.r < b.r;
	return a.o < b.o;
}

int main(){ _
	memset(pd, -INF, sizeof(pd));
	cin >> n;
	set <int> st;
	map<int, int> ma;
	vector<vector<show>> v(n);
	for(int i=0;i <n; i++){
		int m; cin >> m;
		v[i].resize(m);
		for(int j=0; j<m; j++){
			it++;
			show a;
			cin >> a.l >> a.r >> a.o;
			st.insert(a.l);
			st.insert(a.r);
			v[i].pb(a);
		}
		sort(v[i].begin(), v[i].end(), ord);
	}
	int aux =0;
	for(auto k : st) ma[k]=aux++;
	for(int i=0;i <n; i++) for(int j=0; j<v[i].size(); j++) v[i][j].l = ma[v[i][j].l], v[i][j].r=ma[v[i][j].r];
	vector< vector<ii>> w(aux+10);
	for(int i=0;i <n; i++){
		for(int j=0; j<v[i].size(); j++){
			w[v[i][j].r].pb({i, j});
		}
	}
	
	pd[0][0] = 0;
	for(int x=1;x <aux; x++){
		for(int msk=0;msk <(1<<n); msk++){
			pd[x][msk] = max(pd[x][msk], pd[x-1][msk]);
			for(auto p : w[x]) if((1<<p.f) & msk){
				show s = v[p.f][p.s];
				int k = p.f;
				pd[x][msk] = max(pd[x][msk], s.o+max(pd[s.l][msk], pd[s.l][msk^(1<<k)]));
			}
		}
	}	
	int ans = pd[aux-1][(1<<n)-1];
	if(ans>0) cout << ans << endl;
	else cout << -1 << endl;
	exit(0);
}
