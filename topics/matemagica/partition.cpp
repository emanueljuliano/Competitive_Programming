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

// pentagon numbers = n(3n - 1)/2
const int MAX = 5e5+10;
const int MOD = 1e9+7;

int part[MAX];
void partition(int n){
	vector<int> p;
	for(int i=1; i*i<=n; i++)
		p.pb(i*(3*i - 1)/2), p.pb(i*(3*i + 1)/2); 
	part[0] = 1;
	for(int i=1; i<=n; i++) for(int j=0; p[j]<=i; j++){
		if(j%4 < 2) part[i] = (part[i] + part[i-p[j]])%MOD;
		else part[i] = (part[i] - part[i-p[j]] + MOD)%MOD;
	}
}

int main(){ _
	int n = MAX - 10;	
	partition(n);
	for(int i=0; i<=n;i++){
		cout << part[i] << " ";
	}
	cout << endl;
		
	exit(0);
}
