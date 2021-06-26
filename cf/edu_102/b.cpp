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
		string a, b; cin >> a >> b;
		if(a.size()>b.size()) swap(a, b);
		
		string c = b+b;
		bool can = true;
		for(int i=0; i<c.size(); i++){
			if(c[i]!=a[i%(a.size())]) can = false;
		}

		if(can){
			int ans = a.size()*b.size()/gcd(int(a.size()), int(b.size()));
			c.clear();
			for(int i=0;i <ans; i++) c+= a[i%a.size()];
			cout << c << endl;
		}
		else cout << -1 << endl;
	}
	
	
	
	exit(0);
}
