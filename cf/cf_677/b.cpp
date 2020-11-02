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


int main(){ _
		
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int at = 0;
		vector<int> v(n);
		int tot = 0;
		for(auto &i: v) cin >> i, tot+=i;
		int ini = 0, end=0;
		for(int i=0;i <n; i++) if(v[i]) {ini = i; break;}
		for(int i=0;i <n; i++) if(v[i]) {end = i;}
		cout << (end-ini)-tot+1 << endl;
	}
	
	
	exit(0);
}
