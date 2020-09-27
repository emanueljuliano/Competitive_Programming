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
	int n, c; cin >> n >> c;
	vector<int> v(n);
	for(auto &i:v) cin >> i;
	v.pb(-c-1);
	int at = v[0]; int ma = v[0];
	int ans = 0;
	for(int i=1;i <n+1; i++){
		if(ma-v[i] > c and ma-at>c){
			ans += ma-at-c;
			ma = v[i];
			at = v[i];
		}
		else if(v[i] <at){
			at = v[i];
			ma = v[i];
		}
		else if(v[i] > ma){
			ma = v[i];
		}
	}
	cout << ans << endl;

	
	exit(0);
}
