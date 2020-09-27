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
		int n; cin >> n;
		if(n==1) {cout << -1 << endl; continue;}
		if(n%3!=1){
			for(int i=0; i<n-1; i++){
				cout << 2;
			}
			cout << 3 << endl;
		}
		else{
			for(int i=0; i<n-2; i++){
				cout << 2;
			}
			cout << 33 << endl;
		}
	}
	
	
	exit(0);
}
