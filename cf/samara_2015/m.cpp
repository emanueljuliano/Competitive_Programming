#include<bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

int main(){ _
	int n, q; cin >> n >> q;
	for(int i=0;i <q; i++){
		int l, r; cin >> l >> r;
		int ans = n/(l+r)*2;
		if(n%(l+r)>=l) ans++;
		cout << ans << endl;
	}

}
