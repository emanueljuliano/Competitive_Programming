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
	vector<int> v(n);
	for(auto &i : v) cin >> i;
	bool show = true;
	for(int i=0;i <n-1; i++){
		if(v[i]<0) show = false;
		if(v[i]%2) v[i+1]--;
	}
	if(show and v[n-1]%2==0) cout << "YES" << endl;
	else cout << "NO" <<endl;
	
	
	
	exit(0);
}
