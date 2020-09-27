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

const int MAX = 1e7 + 10; 
const int MAX2 = 5e5 + 10; 
const int MOD = 1e9+7;

int mu[MAX];
int val[MAX];
int p2[MAX2];

ll comb(int x){
	return (p2[x]-1+MOD)%MOD;
}

int main(){ _
	p2[0] =1;
	p2[1] = 2;
	for(int i=2;i <MAX2; i++){
		p2[i] = (p2[i-1]*2)%MOD;
	}
  for (int i = 0; i < MAX; i++){
        mu[i] = 1;
        val[i] = i;
    }
    for (int i = 2; i < MAX; i++){
        if (val[i] != i) continue;
        val[i] = 1;
        mu[i] = -1;
        for (int j = i+i; j < MAX; j += i){
            val[j] /= i;
            mu[j] = -mu[j];
        }
    }
    for (int i = 2; i < MAX; i++){
        if (val[i] != 1) mu[i] = 0;
		val[i] = 0;
	}
	
	vector<int> imp;
	int n; cin >> n;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		val[a]++;
		for(int j=2; j*j<=a; j++) if(a%j==0){
			val[j]++;
			if(j*j!=a) val[a/j]++;
		}
	}
	
	ll ans = 0;
	for(int i=2;i <MAX; i++){
		ll at = ans;
		ans = (ans - comb(val[i])*(n-val[i])*mu[i]%MOD + MOD)%MOD;
	//	if(ans!=at) cout << i << " " << ans << endl;
	}
/*	for(int i=0; i<n; i++){
		int at=0;
		for(int j=0; j<fat[i].size(); j++){
			int div = fat[i][j];
		//	cout << div << " "<< val[div] << " " << mu[div] << endl;
			at += mu[div]*(val[div]-1);
		}
		at = abs(at);
		cout << imp[i] << " at = " << at << " comb= " << comb(n-1-at)<< endl;
		ans = (ans+comb(n-1-at))%MOD;
	}
*/
	cout << ans << endl;
	
	exit(0);
}
