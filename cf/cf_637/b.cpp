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
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n>> k;
		vector<int> v, w(n, 0);
		for(int i=0;i <n; i++){
			int a; cin >> a; v.pb(a);
		}
		for(int i=1;i <n-1; i++){
			if(v[i-1] < v[i] and v[i]>v[i+1]) w[i] = 1;
		}
		vector<int> s;
		s.pb(0);
		for(int i=1; i<n;i++){
			s.pb(s[i-1]+w[i]);
		}
		int it = k-1;
		int ans1 = 0, ans2=it;
		int ans = s[it-1] - s[0]+1;
		for(int i=1;i <n-k+1; i++){
			if(s[it+i-1] - s[i]+1 > ans){
				ans1 = i; ans2=it+i;
				ans = s[it+i-1]-s[i]+1;
			}
		}
		cout << ans << " " << ans1+1 << endl;
	}
	
	
	
	exit(0);
}
