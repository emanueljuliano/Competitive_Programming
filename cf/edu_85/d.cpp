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


int main(){ //_
	int t; cin >> t;
	while(t--){
		ll n, l, r; cin >> n >> l >> r;
		ll mod = 2*(n-1);
		ll at = 1;
		while(l-2*(n-at)>0){
			l -= 2*(n-at);
			r -= 2*(n-at);
			at++;
			if(at==n) break;
		}
//		cout << "HM" << l << " " << r  << endl;
		// posso estar no fim
		// posso estar no at
		// posso estar no at+l
		ll com = 0;
		if(l%2)
			com = at;
		else
			com = at+l/2;

		ll tot = r-l;
		while(true){
			if(at==n){
				cout << 1 << " ";
				break;
			}
			else if(at+l/2 == n){
				cout << n << " ";
				l -= 2*(n-at);
				r -= 2*(n-at);
				at++;	
			}
			else{
				if(l%2) cout << at << " ";
				else cout << at+l/2 << " ";
			}
			l++;
			if(l>r) break;
		}
		cout << endl;
	}

	
	
	
	exit(0);
}
