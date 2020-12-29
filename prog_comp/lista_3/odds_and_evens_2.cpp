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

const int MAX = 1e7+1e6;

int main(){ _
	int a, b; cin >> a >> b;
	if(a==b) return cout << "?" << endl, 0;
	if(a>b) swap(a, b);

	vector<bool> pri(MAX, 1);
	vector<int> f2(MAX);
	pri[0] = 0, pri[1] = 0;
	for(int i=2; i<MAX; i++){
		if(i%2==0) f2[i] = f2[i/2]+1;
		if(pri[i]) for(int j=i+i; j<MAX; j+=i) pri[j] = 0;
	}	
	int n = 0;
	for(int i=a; i<=b; i++) n+=pri[i];
	if(!n) return cout << "Bob" << endl, 0;
	int m = abs(a-b);

	int num = n+m-1;
	int d1 = n-1, d2 = m;

	vector<ll> sf2(MAX);
	for(int i=2; i<=num; i++){
		sf2[i] = sf2[i-1] + f2[i];
	}

	if(sf2[num] - sf2[d1] - sf2[d2] > 0) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	
	
	exit(0);
}
