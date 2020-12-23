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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto & i : v) cin >> i;
		vector<ii> cuts;
		vector<int> freq(n+1);
		int it = 0;
		for(int i=0;i <n-1; i++)
			if(v[i]==v[i+1]) cuts.pb({it, i}), freq[v[i]]++, freq[v[it]]++, it=i+1;
		cuts.pb({it, n-1}), freq[v[it]]++, freq[v[n-1]]++;

		auto val = [&](int x){
			vector<int> f = freq;
			int at = cuts.size();
			for(auto [a, b] : cuts) if(at<x){
				for(int j=a; j<b; j++) if(f[v[j]]<=x and f[v[j+1]]<=x and at<x)
					f[v[j]]++, f[v[j+1]]++, at++;
			}
			int maxi = 0;
			for(int i=1; i<=n; i++) maxi = max(maxi, f[i]);
			return maxi<=at+1;
		};
		
		int l = cuts.size(), r = n+1;
		while(l<r){
			int m = (l+r)/2;
			if(val(m)) r = m;
			else l = m+1;
		}
		if(r==n+1) cout << -1 << endl;
		else cout << l-1 << endl;
	}
	
	
	exit(0);
}
