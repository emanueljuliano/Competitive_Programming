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
		vector<int> v(26);
		for(auto &x : v) cin >> x;
		int ans = 0, uns=0;
		for(int i=0;i <26; i++) if(v[i]==1) uns++;
		for(int i=0;i <26; i++) if(v[i]==1){v[i] = 0; ans++; break;}	
		for(int i=0;i <26; i++) if(v[i]>=2) ans+=2;	
		if(ans%2==0){
			if(ans==0){
				cout << "0 0" << endl;
			}
			else{
				int mini = INF;
				for(int i=0;i <26; i++) if(v[i]>=2) mini = min(mini, v[i]);
				cout << ans << " " << mini/2 << endl;
			}
		}
		else{
			for(int i=0;i <26; i++) if(v[i]>=2) uns = min(uns, v[i]/2);
			cout << ans << " " << uns << endl;
		}
		
	}
	
	
	
	exit(0);
}
