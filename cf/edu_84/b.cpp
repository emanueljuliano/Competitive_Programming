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

int pri[(int)1e5+10], pra[(int)1e5+10];

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i=0; i<n; i++) pri[i]=0, pra[i]=0;
		vector<vector<int>> v(n);
		for(int i=0; i<n; i++){
			int k; cin >> k;
			for(int j=0; j<k; j++){
				int a; cin >> a; a--;
				v[i].pb(a);
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<v[i].size(); j++){
				if(pri[v[i][j]]==0){
					pri[v[i][j]]=1;
					pra[i]=1;
					break;
				}
			}
		}
		int a1=-1, a2=-1;
		for(int i=0; i<n; i++){
			if(pra[i]==0){ a1 = i;}
			if(pri[i]==0){ a2 = i;}
		}
		if(a1==-1 and a2==-1){
			cout << "OPTIMAL" << endl;
		}
		else{
			cout << "IMPROVE" << endl;
			cout << a1+1 << " " << a2+1 << endl;
		}
	}
	
	
	
	exit(0);
}
