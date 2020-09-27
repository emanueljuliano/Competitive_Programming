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
		int n, x; cin >> n >> x; x--;
		vector<int> dg(n, 0);
		for(int i=0;i <n-1; i++){
			int a, b; cin >> a >> b; a--; b--;
			dg[a]++; dg[b]++;
		}
		if(dg[x]<=1) cout << "Ayush" << endl;
		else{
			if(n%2) cout << "Ashish" << endl;
			else cout << "Ayush" << endl;
		}
	}
	
	
	
	exit(0);
}
