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
	int t; cin >>t ;
	while(t--){
		int n; cin >> n; int k; cin >> k;
		int ans = n;
		vector<int> v;
		for(int i=0;i <n; i++){
			int a; cin >> a; v.pb(a);
		}
		sort(v.begin(), v.end());
		ans = 0;
		int at = 0;
		while(!v.empty() and v.back()>at){
			ans++;
			int x = v.back();
			while(x==v.back()) v.pop_back();
			at += k;
		}
		cout << ans <<endl;
	}
	
	
	
	exit(0);
}
