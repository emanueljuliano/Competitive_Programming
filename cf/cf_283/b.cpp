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
	int n; cin >> n;
	string s; cin >> s;
	vector<int> v;
	for(auto c : s) v.pb(c-'0');

	vector<int> mini = v;
	for(int i=0; i<n; i++){
		int at = v[i];
		vector<int> cur(n);
		for(int j=0; j<n; j++){
			cur[j] = (v[(i+j)%n]+(10-at))%10;
		}
		for(int j=0; j<n; j++) {
			if(cur[j]<mini[j]){mini = cur; break;}
			else if(cur[j]>mini[j]) {break;}
		}
	}

	for(auto u : mini) cout << u;
	cout << endl;
	
	
	
	exit(0);
}
