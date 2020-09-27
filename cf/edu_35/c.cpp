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
	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(), v.end());
	int a = v[0], b=v[1], c=v[2];
	bool ans = false;
	if(a==1) ans = true;
	if(b==2) ans = true;
	if(a==3 and b==3 and c==3) ans = true;
	if(a==2 and b==4 and c==4) ans = true;
	
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	exit(0);
}
