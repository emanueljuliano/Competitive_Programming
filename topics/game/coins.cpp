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

int k, l;
int pd[(int)1e6+10];
int G(int x){
	if(x==0) return 0;
	if(pd[x]!=-1) return pd[x];
	int ret = 0;
	vector<int> v;
	if(x>=1) v.pb(G(x-1));
	if(x>=k) v.pb(G(x-k));
	if(x>=l) v.pb(G(x-l));
	sort(v.begin(), v.end());
	for(int i=0;i <v.size(); i++){
		if(v[i]==ret) ret++;
	}
	return pd[x] = ret;
}

int main(){ _
	memset(pd, -1, sizeof(pd));
	int m; cin >> k >> l >> m;
	int ans = 0;
	for(int i=0;i <m; i++){
		int a; cin >> a;
		if(G(a)) cout << "A";
		else cout << "B";
	}
	cout << endl;
	
	exit(0);
}
