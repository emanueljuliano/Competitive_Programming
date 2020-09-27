#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MAX = 5e5 + 10;
ll divi[MAX];

vector<ll> pri;
void crivo(ll lim) {
	for (ll i = 1; i <= lim; i++) divi[i] = 1;
		for (ll i = 2; i <= lim; i++) if (divi[i] == 1){
				pri.pb(i);
				for (ll j = i; j <= lim; j += i) divi[j] = i;
		}
	}

int main(){ _
	ll n; cin >> n;
	crivo(n);
	ll at = 1;
	ll maxi = n;
	set<ll> st;
//	cout << pri.size() << endl;
	for(int i=0; i<pri.size(); i++) cout << 1 << " ";
	n -= pri.size();
	st.insert(1);
	vector<int> ans;
	for(int i=2;i <=maxi; i++){
		if(divi[i]==i) continue;
		int div = 0;
		int a = i;
		for(int j=2; j*j<=a; j++){
			if(a%j==0){
				div = a/j;
				while(a%j==0) a/=j;
				break;
			}
		}
		div = max(div, a);
		ans.pb(div);
	}
	sort(ans.begin(), ans.end());
	for(auto i : ans) cout << i << " ";
	cout <<endl;
	//for(auto x : st) cout << x << " ";
	//cout << endl;
	
	
	
	exit(0);
}
