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
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		vector<int> v;
		set<int> st;
		for(int i=0; i<n; i++){
			int a; cin >>a ;
			v.pb(a);
			st.insert(a);
		}
		bool flag = false;
		for(int i=0; i<n; i++){
			if(v[i]==v[(i+1)%n]) flag = true;
		}
		if(st.size()==1) cout << 1 << endl;
		else if(flag) cout << 2 << endl;
		else if(n%2==0) cout << 2 << endl;
		else cout << 3 << endl;

		if(st.size()==1){
			for(int i=0; i<n; i++) cout << 1 << " ";
			cout << endl;
		}
		else if(n%2==0){
			for(int i=0; i<n; i++)
				cout << i%2+1 << " ";
			cout << endl;
		}
		else if(flag){
			bool of = true;
			int at = 0;
			for(int i=0; i<n; i++){
				cout << at+1 << " ";
				at = !at;
				if(v[i]==v[(i+1)%n] and of){
					at = !at;
					of = false;
				}
			}
			cout << endl;
		}
		else{
			for(int i=0; i<n-1; i++)
				cout << i%2+1 << " ";
			cout << 3 << endl;
		}
	}
	
	
	
	exit(0);
}
