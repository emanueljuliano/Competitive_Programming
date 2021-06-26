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
	int t; cin >> t;
	while(t--){
		ll n, k, d1, d2; cin >> n >> k >> d1 >> d2;
		ll res = n-k;
		bool can = false;
		ll a1, a2, a3;
		
		// + +
		a1 = d1+d2, a2=d2, a3=0;
		if(k>=a1+a2+a3 and (k-(a1+a2+a3))%3==0)
			if(res>=2*d1+d2 and (res-(2*d1+d2))%3==0) can = true;
	
		// - +		
		if(d1>d2){
			a2 = d1, a1=0, a3=d1-d2;
			if(k>=a1+a2+a3 and (k-(a1+a2+a3))%3==0)
				if(res>=d1+d2 and (res-(d1+d2))%3==0) can = true;
		}
		else{
			a2 = d2, a1=d2-d1, a3=0;
			if(k>=a1+a2+a3 and (k-(a1+a2+a3))%3==0)
				if(res>=d1+d2 and (res-(d1+d2))%3==0) can = true;
		}
	
		// + -
		a1 = d1, a3=d2, a2 = 0;
		if(k>=a1+a2+a3 and (k-(a1+a2+a3))%3==0){
			if(d1>d2){
				if(res >= d1-d2 + d1 and (res-(d1-d2+d1))%3==0) can = true;
			}
			else{
				if(res >= d2-d1 + d2 and (res-(d2-d1+d2))%3==0) can = true;
			}
		}

		// - -
		a1 = 0, a2=d1, a3=d1+d2;	
		if(k>=a1+a2+a3 and (k-(a1+a2+a3))%3==0)
			if(res>=d1+2*d2 and (res-(d1+2*d2))%3==0) can = true;	
		
		if(can) cout << "yes" << endl;
		else cout <<"no" << endl;
	}
	
	
	
	exit(0);
}
