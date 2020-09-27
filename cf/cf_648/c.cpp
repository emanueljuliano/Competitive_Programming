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
		vector<int> v(n), w(n), a(n+10), b(n+10);
		for(auto &i : v) cin >> i;
		for(auto &i : w) cin >> i;
		map<int, int> dif;
		for(int i=0;i <n; i++){
			b[w[i]] = i;
			a[v[i]] = i;
		}
		for(int i=1; i<=n; i++){
			dif[(a[i]-b[i]+n)%n]++;
		}
		int maxi = 0;
		for(auto x : dif){
			maxi = max(maxi, x.s);
		}
		cout << maxi << endl;

	
	
	
	exit(0);
}
