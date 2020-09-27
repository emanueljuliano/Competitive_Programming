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

vector<vector<int>> v(55);
int n, k, p;

int pd[50*30 +10][55][35];
int rec(int car, int pil, int at){
	if(car==0 or pil==n) return 0;
	if(pd[car][pil][at] != -1) return pd[car][pil][at];
	if(at==k) return pd[car][pil][at] = rec(car, pil+1, 0);
	
	return pd[car][pil][at] = max(v[pil][at] + rec(car-1, pil, at+1), rec(car, pil+1, 0));
}

int main(){ _
	int t; cin >> t;
	int out = 0;
	while(out<t){
		memset(pd, -1, sizeof(pd));
		out++;
		cin >> n >> k>> p;
		for(int i=0; i<n; i++) v[i].clear();
		for(int i=0;i <n; i++){
			for(int j=0; j<k; j++){
				int a; cin >> a;
				v[i].pb(a);
			}
		}
		int ans = rec(p, 0, 0);
		cout << "Case #" << out << ": " << ans << endl;
	}
	
	
	
	exit(0);
}
