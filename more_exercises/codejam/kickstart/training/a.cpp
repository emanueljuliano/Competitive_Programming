#include <bits/stdc++.h>

using namespace std;

//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){// _
	int t; cin >> t;
	while(t--){
		int a, b; cin >> a >> b;
		int n; cin >> n;
		a++;
		for(int i=0; i<n; i++){
			int m = (a+b)/2;
			cout << m << endl;
			string s; cin >> s;
			if(s=="TOO_SMALL") a = m+1;
			else if(s=="TOO_BIG") b = m-1;
			else break;
		}
	}
	
	
	
	exit(0);
}
