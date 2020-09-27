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
const ll LINF = 1e18;

ll h[3][55];
ll d[2][3][55];
int fim[3];
vector<pair<ii, int>> ar[3];

int main(){ _
	int p; cin >> p;
	vector<ii> tam(p);
	for(int i=0; i<p; i++){
		cin >> tam[i].f >> tam[i].s;
		for(int j=0;j <tam[i].f; j++){
			cin >> h[i][j];
		}
		for(int j=0;j <tam[i].s; j++){
			int a, b, c; cin >> a >> b >> c; a--; b--;
			ar[i].pb({{a, b}, c});
		}
		cin >> fim[i]; fim[i]--;
	}
	
	for(int i=0;i <p; i++) for(int j=0; j<tam[i].f; j++) d[0][i][j] = LINF;
	for(int i=0;i <p; i++) d[0][i][0] = 0;
	
	bool show = true;
	for(int i=0;i <p; i++) show &= fim[i]==0;
	ll ans = LINF;
	if(show) ans = 0;
	
	int IT = 50*50*45;
	for(int i=1;i <IT; i++){
		ll at = 0;
		for(int k=0;k<p; k++){
			for(int j=0;j <tam[k].f; j++) d[i%2][k][j] = LINF;
			
			for(int j=0; j<tam[k].f; j++)
				d[i%2][k][j] = min(d[i%2][k][j], d[(i-1)%2][k][j]+h[k][j]);
			
			for(auto e : ar[k]){
				int b = e.f.s, a = e.f.f, c = e.s;
				d[i%2][k][b] = min(d[i%2][k][b], d[(i-1)%2][k][a]+c);
			}
			at += d[i%2][k][fim[k]];
		}
		ans = min(ans, at);
	}
	
	cout << ans << endl;
		
	exit(0);
}
