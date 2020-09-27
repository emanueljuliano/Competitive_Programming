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
	
	set<int> st;
	while(t--){
		st.clear();
		int maxi = 0;
		int n; cin >> n;
		int nn = n;
		int at = 0;
		int ans1, ans2;
		vector<int> v;
		
		for(int i=0; i<n; i++){
			int a; cin >> a;
			v.pb(a);
			maxi = max(a, maxi);
		}
		
		vector<int> aux(maxi+2, 0);
		for(int i=0;i <n; i++){
			aux[v[i]]++;
		}
		bool flag = true;
		if(aux[1]==1) flag = false;
		for(int j=1; j<=maxi; j++){
			if(aux[j]>2) flag = false;
			if(aux[j]==0) flag = false;
			if(aux[j]<aux[j+1]) flag = false;
		}
		if(!flag){	
			cout << 0 << endl;
			continue;
		}



		vector<ii> ans;
		for(int i=0; i<nn; i++){
			if(st.count(v[i])){
				vector<int> pode(maxi+2, 0);
				int maux = 0;
				for(int j=0; j<i; j++){
					pode[v[j]]++;
					maux = max(maux, v[j]);
				}
				for(int j=1; j<=maux; j++){
					if(pode[j]!=1) flag = false;
				}
			
				for(int j=0; j<=maxi; j++) pode[j] = 0;
				int a1 = maux;	
				maux = 0;
				
				for(int j=i; j<n; j++){
					pode[v[j]]++;
					maux = max(maux, v[j]);
				}
				for(int j=1; j<=maux; j++){
					if(pode[j]!=1) flag = false;
				}

				if(flag){
					ans.pb({a1, maux});
				}
				break;
			}
			else st.insert(v[i]);
		}
		st.clear();
		for(int i=nn-1; i>=0; i--){
			if(st.count(v[i])){
				bool flag = true;
				vector<int> pode(maxi+2, 0);
				int maux = 0;
				for(int j=n-1; j>i; j--){
					pode[v[j]]++;
					maux = max(maux, v[j]);
				}
				for(int j=1; j<=maux; j++){
					if(pode[j]!=1) flag = false;
				}
				
				for(int j=0; j<=maxi; j++) pode[j] = 0;
				int a1 = maux;
				maux = 0;
			
				for(int j=0; j<=i; j++){
					pode[v[j]]++;
					maux = max(maux, v[j]);
				}
				for(int j=1; j<=maux; j++){
					if(pode[j]!=1) flag = false;
				}

				if(flag){
					ans.pb({maux, a1});
				}
				break;
			}
			else st.insert(v[i]);
		}
	
		if(ans.size()==0){
			cout << 0 << endl;
		}
		if(ans.size()==2){
			if(ans[0]==ans[1]){
				cout << 1 << endl;
				cout << ans[0].f << " " << ans[0].s << endl;
			}
			else{
				cout << 2 << endl;
				cout << ans[0].f << " " << ans[0].s << endl;
				cout << ans[1].f << " " << ans[1].s << endl;
			}
		}
		if(ans.size()==1){
			cout << 1 << endl;
			cout << ans[0].f << " " << ans[0].s << endl;
		
		}





	}
	exit(0);
}
