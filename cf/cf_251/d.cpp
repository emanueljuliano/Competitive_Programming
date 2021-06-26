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

int main(){ _
	int n, m; cin >> n >> m;
	vector<ll> v(n), w(m);
	for(auto &i : v) cin >> i;
	for(auto &i : w) cin >> i;
	sort(v.begin(), v.end(), greater<>());
	sort(w.begin(), w.end());
	
	ll mini = 1, maxi = 1;
	ll a = v.back(), b = w.back();
	v.pop_back(), w.pop_back();
	while(v.size() and v.back()==a) v.pop_back(), mini++;
	while(w.size() and w.back()==b) w.pop_back(), maxi++;
	
	ll ans = 0;
	while(a<b){
		if(!v.size() and !w.size()){
			ans += (b-a)*min(mini, maxi);
			break;
		}
		else if(mini<maxi){ // aumenta a
			if(!v.size() or v.back()>=b){
				ans += (b-a)*mini;
				break;
			}
			ans += (v.back()-a)*mini;
			a = v.back();
			while(v.size() and v.back()==a) v.pop_back(), mini++;
		}
		else{
			if(!w.size() or w.back()<=a){
				ans += (b-a)*maxi;
				break;
			}
			ans += (b-w.back())*maxi;
			b = w.back();
			while(w.size() and w.back()==b) w.pop_back(), maxi++;
		}
	}

	cout << ans << endl;
	
	exit(0);
}
