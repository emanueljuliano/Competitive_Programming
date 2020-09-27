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

const int MAX = 3e5+10;
ll soma[2][MAX];
ll soma2[2][MAX];
ll s[2][MAX];
ll v[2][MAX];

int main(){ _
	int n; cin >> n;
	for(int i=0;i <2; i++) for(int j=0; j<n; j++) cin >> v[i][j];
	
	ll at = 0, a=0, at2=0;
	ll mul = 1;
	for(int i=0;i<n; i++){
		s[1][i] = v[1][i]+a;
		soma[1][i] = mul*v[1][i]+at;
		at = soma[1][i], a=s[1][i];
		mul++;
	}
	for(int i=n-1; i+1; i--){
		s[0][i] = v[0][i]+a;
		soma[0][i] = mul*v[0][i]+at;
		at = soma[0][i], a=s[0][i];
		mul++;
	}
	soma[0][0] = soma[0][1];

	mul = 0;
	for(int i=0;i<n; i++){
		soma2[0][i] = mul*v[0][i]+at2;
		at2 = soma2[0][i];
		mul++;
	}
	for(int i=n-1; i+1; i--){
		soma2[1][i] = mul*v[1][i]+at2;
		at2 = soma2[1][i];
		mul++;
	}

	ll ans = max(soma2[1][0], soma[0][0]);
	int row = 1;
	at = v[1][0];
	for(int i=1;i <n; i++){
		ll nat1;
		if(row==0) {
			nat1 = (soma2[1][i] - soma2[0][i-1]) + at + (ll)(i)*(s[0][i]-s[1][i-1]); //dir
			at+= (ll)(2*i)*v[0][i]+(ll)(2*i+1)*v[1][i];
		}
		else{
			nat1 = (soma[0][i] - soma[1][i-1]) + at + (ll)(i-1)*(s[0][i]-s[1][i-1]); //esq
			at+= (ll)(2*i)*v[1][i]+(ll)(2*i+1)*v[0][i];
		}
		ans = max(ans, nat1);
		ans = max(ans, at);
		row = !row;
	}
	cout << ans << endl;


	
	
	exit(0);
}
