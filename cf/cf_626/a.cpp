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
		int ans = 0;
		int ev=0, od=0;
		int n; cin >> n;
		vector<int> v;
		for(int i=0;i <n; i++){
			int a; cin >> a;
			if(a%2==0)ev++;
			else od++;
			v.pb(a);
		}
		if(ev==0 and n==1) cout << -1 <<endl;
		else if(ev>=1){
			cout << 1 << endl;
			for(int i=0;i <v.size(); i++) if(v[i]%2==0){cout << i+1 << endl; break;}
		}
		else{
			cout << 2 << endl;
			bool flag = false;
			for(int i=0;i <v.size(); i++){
				if(v[i]%2) {
					cout << i+1 << " ";	
					if(flag) break;
					flag = true;
				}
			}
			cout << endl;
		}
	
	}
	
	
	
	exit(0);
}
