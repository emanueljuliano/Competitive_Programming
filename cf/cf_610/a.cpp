#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
		
	int t;
	cin >> t;
	for(int k=0; k<t; k++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a>b) swap(a, b);
		int ma = c+d;
		int me = c-d;
		int ans = b-a;
		if(me<a and ma>b) ans = 0;
		else if(me<a and ma>a) ans = b-ma;
		else if (ma>b and me<b) ans = me-a;
		else if(me>=a and ma<=b) ans = b-ma + me-a;
		cout << ans << endl;
	}	

	exit(0);
}
