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
int divi[MAX], vis[MAX];

void crivo(int lim) {
		for (int i = 1; i <= lim; i++) divi[i] = 1;

			for (int i = 2; i <= lim; i++) if (divi[i] == 1)
						for (int j = i; j <= lim; j += i) divi[j] = i;
}

int ans = 1;

vector<ii> v;
void fact(int n) {
	while(n != 1){
		int no = n;
		ii at = {divi[no], 0};
		while(n%divi[no]==0){
			at.s++;
			n/=divi[no];
		}
		v.pb(at);
	}
}

void solve(int n, int i){
	if(i==v.size()){
		if(vis[n]) ans = max(ans, n);
		else vis[n] = 1;
		return;
	} 
	solve(n, i+1);
	for(int j=0; j<v[i].s; j++){
		n*= v[i].f;
		solve(n, i+1);
	}
}

int main(){ _
	crivo(MAX-5);
	
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int a; cin >> a;
		v.clear();
		fact(a);
		solve(1, 0);
	}
	cout << ans << endl;
	exit(0);
}
