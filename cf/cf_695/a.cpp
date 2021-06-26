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
		int n; cin >> n;
		if(n==1) cout << 9 << endl;
		else if(n==2) cout << "98" << endl;
		else{
			cout << "98";
			for(int i=2; i<n; i++) cout << (7+i)%10;
			cout << endl;
		}
	}
	
	
	
	exit(0);
}
