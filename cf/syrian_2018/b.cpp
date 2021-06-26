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
	freopen("hamming.in", "r", stdin);	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string a, b; cin >> a >> b;
		int a1=0, a0=0, b1=0, b0=0;
		for(auto c : a) a1 += (c-'0')^0, a0 += (c-'0')^1;
		for(auto c : b) b1 += (c-'0')^0, b0 += (c-'0')^1;
		cout << min(a1, b0) + min(a0, b1) << endl;
	}
	
	
	exit(0);
}
