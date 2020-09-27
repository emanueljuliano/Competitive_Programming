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
		int n, k; cin >> n >> k;
		vector<int> v(n);
		for(auto &i:v) cin >> i;
		
		// existe k --- senao ja era
		// subsequencia de tamanho 2 com k,  >=k ---- show
		// k = maior nao da
		
		bool sub = false;
		bool ma = false;
		int nk  =0;
		for(int i=0;i <n; i++){
			if(v[i]==k){ nk++;
			}
			if(v[i]>=k){
				if(i!=0 and v[i-1]>=k) ma = true;
				if(i!=n-1 and v[i+1]>=k) ma = true;
			}
			if(i!=0 and i!=n-1){
				int s = 0;
				s += v[i-1]>=k;
				s += v[i]>=k;
				s += v[i+1]>=k;
				if(s>1) ma = true;
			}
		}
		
		if(nk==0) cout << "no" << endl;
		else if(nk==n) cout << "yes" << endl;
		else if(ma) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	
	
	
	
	exit(0);
}
