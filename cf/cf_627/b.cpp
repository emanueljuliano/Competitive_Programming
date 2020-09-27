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
		vector<int> v;
		multiset<int> st;
		for(int i=0; i<n; i++){
			int a; cin >> a;
			v.pb(a);
			st.insert(a);
		}
		bool flag = false;
		for(int i=0; i<v.size(); i++){
			int a = v[i];
			if(st.count(a)>=3) flag = true;
			else if(st.count(a)==2){
				if(i==0 and v[i+1]!=a){
					flag = true;
				}
				else if(i==0) continue;
				else if(i==n-1) continue;
				else if(v[i+1]!=v[i] and v[i-1]!=v[i]) flag = true;
			}
		}
		if(flag){
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;	
	}
	
	
	
	exit(0);
}
