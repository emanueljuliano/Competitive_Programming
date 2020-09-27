#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
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
		int n, h; cin >> h >> n;
		vector<int> v;
	//	v.pb(h);
		for(int i=0;i <n; i++){
			int a; cin >> a; v.pb(a);
		}
	
			
		
		
		
		
		
		
		/*
		//	reverse(v.begin(), v.end());
		int at = 0;
		int ans = 0;
		for(int i=0;i <v.size()-1; i++){
			int old = ans;
			if(v[i]<=at) continue;
			if(v[i]-at==2) {at = v[i];}
			else if(v[i+1]-at==2) {at = v[i+1]; i++;}
			else if(v[i]-at==1){
				if(at!=0){
					at = v[i]+1;
					ans++;
				}
				else{
					at = v[i];
				}
			}
			else if(v[i]-at==3){
				if(v[i+1]-at==4) at+=2;
				else at++;
				ans++;
				i--;
			}
			else{
//				cout << v[i] << " " << at << endl;
				int aux = (v[i]-at)/2-1;
				ans+=aux;
				at += 2*aux;
				i--;
			}
//			if(ans != old) cout << v[i] << endl;
		}
		cout << ans << endl;
	}
	
	*/
	exit(0);
}
