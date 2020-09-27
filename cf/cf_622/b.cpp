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
	int t; cin >> t;
	while(t--){
		int n, x, y; cin >> n >> x >> y;
		if(x>y) swap(x, y);
			
		int qmini = x+y+1;
		int qmaxi = x+y-1;
		//mini
		
		int pos = n-y;
		int mini = 1, maxi=n;
		int acima = 0;
		if(x+y<n){
			mini = 1;	
		}
		else{
			int k = (x+y+1)-n;
			mini = min(n, k);
		}
		// maxi
		
		if(x+y>n)
			maxi = n;

		else{
			int k = (x+y);
			maxi = k-1;
		}
		cout << mini << " " << maxi << endl;
	}
	
	
	
	exit(0);
}
