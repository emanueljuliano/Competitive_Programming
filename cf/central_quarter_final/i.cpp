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
	int n; cin >> n; n/=2;
	vector<int> div;
	for(int i=1; i*i<=n; i++) if(n%i==0){
		div.pb(i);
		if(i*i != n) div.pb(n/i);
	}
	sort(div.begin(), div.end());
	cout << div.size() << endl;
	for(auto u : div) cout << u << " ";
	cout << endl;
	
	exit(0);
}
