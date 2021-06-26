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

vector<ll> freq(26);
bool solve(ll x, ll i){
	if(x==0) return true;
	if(i<0) return false;
	x = abs(x);
	if(freq[i]*(1LL<<i) <= x){
		if(solve(x - freq[i]*(1LL<<i), i-1)){
			freq[i] = 0; return true;
		} 
		return false;
	}
	else{
		ll div = x/(1LL<<i);
		div++;
		if(div<=freq[i] and solve(x-div*(1LL<<i), i-1)){
			freq[i]-=div; return true;
		}
		div--;
		if(solve(x-div*(1LL<<i), i-1)){
			freq[i]-=div; return true;
		}
		return false;
	}
};

int main(){ _
	ll n, t;
	string s;
	cin >> n >> t;
	cin >> s;

	t-=(1LL<<(s[n-1]-'a'));
	t+=(1LL<<(s[n-2]-'a'));
	if(n==2 and t==0) return cout << "Yes" << endl, 0;
	if(n==2 and t!=0) return cout << "No" << endl, 0;
	
	t = abs(t);	
	for(ll i=0;i <n-2; i++) freq[s[i]-'a']++;
	if(!solve(t, 25)) return cout << "No" << endl, 0;
	
	for(ll i=25; i+1; i--) if(freq[i]%2){
		if(!solve(1<<i, i-1)) return cout << "No" << endl, 0;
	}

	cout << "Yes" << endl;
	
	exit(0);
}
