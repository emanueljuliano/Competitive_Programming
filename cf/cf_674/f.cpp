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

const int MOD = 1e9+7;

int main(){ _
	int n; cin >> n;
	string s; cin >> s;
	vector<int> c(n+1), bc(n+1), abc(n+1);
	c[n] = 0, bc[n] = 0, abc[n]=0;

	vector<ll> p3(n+1);
	p3[0] = 1;
	for(int i=1;i <=n; i++) p3[i] = p3[i-1]*3%MOD;
	
	int in = 0;
	for(int i=n-1; i+1; i--){
		c[i] = c[i+1];
		if(s[i]=='c'){
			c[i] = (c[i] + p3[in])%MOD;
		}
		if(s[i]=='?'){
			c[i] = (c[i] + 2*c[i+1]%MOD)%MOD;
			c[i] = (c[i]+p3[in])%MOD;
			in++;
		}
	}

	for(int i=n-1; i+1; i--){
		bc[i] = bc[i+1];
		if(s[i]=='b' or s[i]=='?'){
			bc[i] = (bc[i] + c[i+1])%MOD;
		}
		if(s[i]=='?'){
			bc[i] = (bc[i] + 2*bc[i+1]%MOD)%MOD;
		}
	}

	for(int i=n-1; i+1; i--){
		abc[i] = abc[i+1];
		if(s[i]=='a' or s[i]=='?'){
			abc[i] = (abc[i] + bc[i+1])%MOD;
		}
		if(s[i]=='?'){
			abc[i] = (abc[i] + 2*abc[i+1]%MOD)%MOD;
		}
	}
	
	cout << abc[0] << endl;
	
	exit(0);
}
