#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef __int128 lll;
typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int main(){ _
	int n; cin >> n;
	vector<int>v(n), freq(n);
	vector<lll> rand(n), hash(n+1);
	
	hash[0]=0;
	for(int i=0; i<n; i++) rand[i] = ((ll)rng()<<32LL) + (ll)rng();
	for(int i=0; i<n; i++){
		cin >> v[i];v[i]--;
		
		int &f = freq[v[i]], a=v[i];
		hash[i+1] = hash[i] - f*rand[a] + (f+1)%3*rand[a];
		f = (f+1)%3;
	}

	int it = 0;
	vector<int> f2(n);
	map<ll, int> mp;
	ll ans = 0;
	for(int i=0;i <n; i++){
		f2[v[i]]++;
		if(f2[v[i]]>3){
			while(v[it]!=v[i]) f2[v[it]]--, mp[hash[it]]--, it++;
		 	f2[v[it]]--, mp[hash[it]]--, it++;
		}

		ans += mp[hash[i+1]];
		mp[hash[i]]++;
	}
	cout << ans << endl;

	exit(0);
}
