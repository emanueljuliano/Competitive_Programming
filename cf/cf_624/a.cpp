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
	int t;cin >> t;
	while(t--){
		int a, b; cin >> a >> b;
		if(a==b) {cout << 0 << endl; continue;}
		else if(b<a and a%2==b%2) cout << 1 << endl;
		else if(b<a) cout << 2 << endl;
		else if(b>a and a%2!=b%2) cout << 1 << endl;
		else cout << 2 << endl;
	}
	
	
	
	exit(0);
}
