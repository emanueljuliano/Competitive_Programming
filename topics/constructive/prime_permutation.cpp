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
	vector<int> p;
	auto is_prime = [&](int x){
		for(int j=2; j*j<=x; j++) if(x%j==0) return false;
		return true;
	};
	string s; cin >> s;
	for(int i=2; i<=s.size(); i++) if(is_prime(i)) p.pb(i);

	vector<int> f(26);
	for(auto c : s) f[c-'a']++;
	int maxi = 0;
	int a = 0;
	for(int i=0;i <26; i++) if(f[i]>maxi) maxi = f[i], a = i;
	vector<int> sieve(s.size());
	int need = 0;
	for(auto x : p) if(2*x<=s.size()){
		for(int i = 1; i<=s.size()/x; i++) if(!sieve[i*x-1]) sieve[i*x-1]=1, need++;
	}
	if(need > maxi) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	string ans;
	for(int i=0;i <s.size(); i++) ans.pb('a'-1);
	for(int i=0;i <s.size(); i++) if(sieve[i]) ans[i]=('a'+a), f[a]--;
	
	int it = 0;
	for(int i=0;i <26; i++){
		for(int j=0; j<f[i]; j++){
			while(ans[it]>='a') it++;
			ans[it] = i+'a';
		}
	}
	cout << ans << endl;
	
	
	exit(0);
}
