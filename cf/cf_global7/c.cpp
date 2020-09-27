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


int main(){ _
	int k, n; cin >> k >> n;
	vector<ll> v;
	for(int i=0; i<k; i++){
		ll a; cin >> a;
		v.pb(a);
	}
	ll mini = k-n;
	ll ans = ((ll)mini+1 + (ll)k)*(ll)n/(ll)2;
	ll at = 0;
	ll resp = 1;
	bool flag = false;
	for(int i=0; i<k; i++){
		at++;
		if(v[i]>mini){
			if (flag){
				resp = resp*at%(ll)998244353;
				resp %= 998244353;
			}
			flag = true;
			at = 0;
		}
	}
	//if(at!=0)resp = resp*at%998244353;
	cout <<ans << " " << resp << endl;
	exit(0);
}
