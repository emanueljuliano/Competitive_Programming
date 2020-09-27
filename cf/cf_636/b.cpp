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
		int n; cin>> n;
		if(n/2%2){cout << "NO" << endl; continue;}
		cout << "YES" << endl;
		for(int i=2;i <=n;i+=2){
			cout << i << " ";
		}
		for(int i=1;i <n-1;i+=2){
			cout << i << " ";
		}
		cout << n+n/2-1 << endl;

	}
	
	
	
	exit(0);
}
