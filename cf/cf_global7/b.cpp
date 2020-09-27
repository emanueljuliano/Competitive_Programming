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
	int n; cin >> n;
	vector<int> b;
	for(int i=0; i<n; i++){
		int a; cin >> a;
		b.pb(a);
	}
	vector<int> v;
	v.pb(b[0]);
	int maxi = b[0];
	for(int i=1; i<n; i++){
		v.pb(b[i]+maxi);
		maxi = max(maxi, v.back());
	}
	for(int i=0; i<n; i++)
		cout << v[i] << " ";
	cout << endl;
	exit(0);
}
