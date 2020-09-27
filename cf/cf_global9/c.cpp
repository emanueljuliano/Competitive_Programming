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
		vector<int> v(n);
		vector<int> mE;
		int mini = INF;
		for(auto &i : v){
			cin >> i;
			if(i<mini) mini = i;
			mE.pb(mini);
		}
		int at = v.back();
		bool show = true;
		for(int i=n-1;i>=0; i--){
			if(v[i]>at and mE[i]>=v[i]) show = false;
		}
		if(show) cout << "YES" << endl;
		else cout <<"NO" << endl;
	}
	
	
	
	exit(0);
}
