#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;


int main(){ _
	int t; cin >> t;
	while(t--){
		int n;
		string s; cin >> s >> n;
		int sum=0;
		for(auto c : s) sum += (c-'0');
		ll ans = 0;
		int it = 1;
		vector<ll> p10;
		p10.pb(1);
		for(int i=1;i <=19; i++) p10.pb(p10.back()*10);
		while(sum>n and it<=s.size()){
		//	cout << s << " " << sum << " " << ans << endl;
			int pos = s.size()-it;
			ans += p10[it]-(s[pos]-'0')*p10[it-1];
			sum -= (s[pos]-'0');
			pos--;
			it++;
			while(pos>=0 and s[pos]=='9') sum-=9, it++, pos--;
			sum++;
			if(pos+1)s[pos]++;
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
