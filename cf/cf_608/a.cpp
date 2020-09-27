#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int ans = 0;
	if(e>f){
		ans += e*min(a, d);
		a -= ans/e;
		d -= ans/e;
		ans += f*min(b, min(d, c));
	}
	else{
		ans += f*min(b, min(d, c));
		d-= ans/f;
		ans += e*min(a, d);
	}

	cout << ans << endl;
	exit(0);
}
