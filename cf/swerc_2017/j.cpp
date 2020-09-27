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
	vector<ll> v(n), w(n);
	for(auto &i : v) cin >> i;
	for(auto &i : w) cin >> i;
	ll b0=0, b1=0, b2=0;
	ll a0=0, a1=0, a2=0;
	for(int i=0;i <n; i++){
		if(i%3==0)a0+=v[i];
		if(i%3==1)a1+=v[i];
		if(i%3==2)a2+=v[i];
	}
	for(int i=0;i <n; i++){
		if(i%3==0)b0+=w[i];
		if(i%3==1)b1+=w[i];
		if(i%3==2)b2+=w[i];
	}
	
	ll whi = b0*a0 + b1*a2 + b2*a1;
	ll yel = b0*a1 + b1*a0 + b2*a2;
	ll pin = b0*a2 + b1*a1 + b2*a0;
	
	cout << yel << " " << pin << " " <<whi << endl;

	exit(0);
}
