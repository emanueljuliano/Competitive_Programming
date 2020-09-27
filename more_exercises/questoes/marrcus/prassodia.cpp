#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

int n;
vector<int> v1, v2, v3;
bool rec(int a, int d, int h, int p, int num){
	if(a==0 and d==0 and h==0 and num>1) return true;
	if(p==n) return false;
	return rec(a-v1[p], d-v2[p], h-v3[p], p+1, num+1) or rec(a, d, h, p+1, num);
}

int main(){ _
	int a, d, h;
	cin >> n >> a >> d >> h;
	for(int i=0; i<n; i++){
		int x, y, z;
		cin >> x >> y >> z;
		v1.pb(x);
		v2.pb(y);
		v3.pb(z);
	}
	bool ans = rec(a, d, h, 0, 0);
	if(ans) cout << "Y" << endl;
	else cout << "N" << endl;

	exit(0);
}
