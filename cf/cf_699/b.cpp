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
		int n, k; cin>> n >> k;
		vector<int> v(n);
		for(auto &i : v) cin >> i;

		int end = -2;
		for(int i=0;i <k; i++){
			end = -2;
			for(int j=0; j<n-1; j++){
				if(v[j+1]>v[j]) {v[j]++, end=j; break;}
			}
			if(end==-2) break;
		}
		cout << end+1 << endl;
	}
	
	
	
	exit(0);
}
