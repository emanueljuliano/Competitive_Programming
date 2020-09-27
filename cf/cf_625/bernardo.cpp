#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
int main(){ _
 
	int n; cin >> n;
	set<pii> s;
	for(int i=0; i<n; i++) {
		int b; cin >> b;
		s.insert({i,b});
	}
	
	ll maxi = 0;
 
	for(auto a : s) {
		
		int piv = a.ss;
		int i = a.ff;
		ll counter = piv;
 
		for(auto b : s) {
			if(b == a) continue;
 
			if(b.ss - piv == b.ff - i) {
				counter += b.ss;
				s.erase(b);
			}
		}
		s.erase({i,piv});
 
		maxi = max(counter, maxi);
	}
 
	cout << maxi << endl;
 
	exit(0);
}
