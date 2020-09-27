#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool ord(ii a, ii b){
	if(a.f==b.f) return (b.s<a.s);
	return a.f<b.f;
}

int main(){ _
	int n;
	cin >> n;
	vector<ll> a(n), t(n);
	set<ll> se;
	for(int i=0; i<n; i++){cin >> a[i];}
	for(int i=0; i<n; i++) cin >> t[i];
	
	vector<ii> v;
	for(int i=0;i<n; i++) v.pb({a[i], t[i]});
	sort(v.begin(), v.end(), ord);
	
	ll ans = 0;
	multiset<ll> at;
	ll soma = 0;
	int x = -1;
	for(int i=0; i<n-1;i++){
		if(v[i].f==v[i+1].f){
			bool vazio = true;
			if(!at.empty()){
				vazio = false;
				i++;
			}
			while(i<n-1 and v[i].f == v[i+1].f){
				at.insert(v[i].s);
				soma += v[i].s;
				++i;
			}

			at.insert(v[i].s);
			soma += v[i].s;
			if(vazio){
				soma -= *at.rbegin();
				at.erase(at.find(*at.rbegin()));
			}
			i--;
		}
		else{
			if(!at.empty()){
				for(int j=v[i].f+1; j<v[i+1].f; j++){
					if(at.empty()) break;
					ans += soma;
					soma -= *at.rbegin();
					at.erase(at.find(*at.rbegin()));
					x = j;
				}
			}
			if(!at.empty()){
				ans += soma;
				soma += v[i+1].s;
				
				at.insert(v[i+1].s);
				soma -= *at.rbegin();
				
				at.erase(at.find(*at.rbegin()));
				x++;
			}
		}	
	}
		while(!at.empty()){
			ans += soma;
			soma -= *at.rbegin();
			at.erase(at.find(*at.rbegin()));
		}
	cout << ans << endl;
	exit(0);
}
