#include <bits/stdc++.h>

using namespace std;

#define debbuging true
#define debug if(debbuging) cout
#define _ if(!debbuging) ios_base::sync_with_stdio(0); cin.tie(0);
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
	int it = 1;
	vector<int> ans(n+1);
	for(int i=2; i<=n; i++) if(!ans[i]){
		bool used = false;
		for(int j=1; j<=n/i; j++) if(!ans[j*i]) ans[j*i] = it, used=true;
		if(used) it++;
	}

	for(int i=2; i<=n; i++) cout << ans[i] << " ";
	cout << endl;


	exit(0);
}
