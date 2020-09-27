#include <bits/stdc++.h>

using namespace std;

//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ //_
	freopen("cubes.in", "r", stdin);
	int t; cin >> t;
	int cs = 0;
	while(t--){ cs++; cout << "Case " << cs << ":" << endl;
		int n; cin >> n;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		sort(v.begin(), v.end(), greater<>());
		vector<int> ans(n);
		int a = 0, b=n-1;
		for(int i=0;i <n; i+=2){
			ans[a] = v[i];
			a++;
			if(i!=n-1) ans[b] = v[i+1];
			b--;
		}
		reverse(ans.begin(), ans.end());
		for(auto k : ans) cout << k << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
