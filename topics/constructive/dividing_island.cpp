#include <bits/stdc++.h>

using namespace std;

#define debbuging true
#define debug if(debbuging) cout
#define _ if(!debbuging) ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int a, b, c, d, n; cin >> a >> b >> c >> d >> n;
	vector M(max(b, d), vector<char>(a+c, '.'));
	
	vector<int> v(n);
	int tot = 0;
	for(auto &i: v) cin >> i, tot+=i;
	if(tot > a*b + c*d) return cout << "NO" << endl, 0;

	vector<char> ans;
	for(int i=0;i <n; i++) for(int j=0; j<v[i]; j++) ans.pb('a'+i);
	for(int i=0;i <a*b+c*d; i++) ans.pb('.');
	int it = 0;
	
	auto fill = [&](int i, int mod){
		int ini = 0, end=a+c;
		if(b>d and i>=d) end = a;
		if(b<d and i>=b) ini = a;
		if(i%2==mod) for(int j=ini; j<end; j++) M[i][j] = ans[it++];
		else for(int j=end-1; j>=ini; j--) M[i][j] = ans[it++];	
	};
	
	if(b>=d and d%2==0) for(int i=0;i <max(b, d); i++) fill(i, 0);
	else if(b>=d and d%2==1) for(int i=0;i <max(b, d); i++) fill(i, 1);
	else if(b%2==0) for(int i=0;i <max(b, d); i++) fill(i, 1);
	else if(b%2==1) for(int i=0;i <max(b, d); i++) fill(i, 0);

	cout << "YES" << endl;
	for(auto u : M){
		for(auto x : u) cout << x;
		cout << endl;
	}

	exit(0);
}
