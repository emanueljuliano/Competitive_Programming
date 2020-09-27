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
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(auto &i:v) cin >> i;
	
	map<int, int> mp;
	int last=0;
	ll ans = 0;

	for(int i=0;i <n; i++){
		mp[v[i]]++;
		if(mp[v[i]]>=k){
			while(v[last]!=v[i]) mp[v[last]]--, last++;
			mp[v[last]]--; last++;
		}
		ans += last;
	}

	cout << ans << endl;
	
	exit(0);
}
