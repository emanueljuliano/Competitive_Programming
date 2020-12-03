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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll choice(ll a, ll b){ // a!/b!/(a-b)!
	if(a<b) return 0;
	vector<int> v(a+10), w(a+10);

	__int128 ret = 1;
	for(int j=2;j <=a; j++){
		ret *= j;
		for(int i=2;i <=b; i++) if(ret%i==0 and !v[i]) ret/=i, v[i]=1;
		for(int i=2;i <=a-b; i++) if(ret%i==0 and !w[i]) ret/=i, w[i]=1;
	}
//	cout << "choice " << (ll)ret << endl;
	return ret;
}

vector<ll> v, pref;
ll solve(ll at, int k, int pos){
	if(!k) return 1;
	if(v[0]>=at) return 0;
	for(int i=0;i <pos; i++)
		if(v[i]<at and v[i+1]>=at)
			return choice(i, k) + solve(at-v[i], k-1, i-1);
//	cout << at << " "<< k << " " << pos << endl;
	return choice(pos, k) + solve(at-v[pos], k-1, pos-1);
}

int main(){ _
	int n, k; cin >> n >> k;
	v.resize(n);
	for(auto &i : v) cin >> i;
	sort(v.begin(), v.end());

	ll a, b; cin >> a >> b;
	cout << solve(b+1, k, n-1) - solve(a, k, n-1) << endl;
	exit(0);
}
