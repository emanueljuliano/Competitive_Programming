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
		int n; cin >> n;
		vector<int> v;
		for(int i=0; i<n; i++){
			int a; cin >> a;
			v.pb(a);
		}
		sort(v.begin(), v.end(), greater<>());
		for(int i=0; i<n; i++)
			cout << v[i] << " ";
		cout <<endl;
	}
	
	
	
	exit(0);
}
