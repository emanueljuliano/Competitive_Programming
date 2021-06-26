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
		int n; cin >> n;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		vector<int> bad(n);
		int tot = 0;
		for(int i=1; i<n-1; i++){
			if(v[i-1]>v[i] and v[i+1]>v[i]) bad[i]=true, tot++;
			if(v[i-1]<v[i] and v[i+1]<v[i]) bad[i]=true, tot++;
		}
		
		int best = 0;
		if(tot) best = 1;
		for(int i=0; i<n-2; i++){
			if(bad[i] and bad[i+1] and bad[i+2]) best = 3;
		}
		for(int i=1; i<n-2; i++) if(best!=3 and bad[i] and bad[i+1]){
			if(i==1 or i+1==n-2) {best = 2; break;}
			else if(v[i-1]==v[i-2]) best = 2;
			else if(v[i+2]==v[i+3]) best = 2;
			else if(v[i]<v[i+1] and v[i+1]<=v[i-1]) best = 2;
			else if(v[i]>v[i+1] and v[i+1]>=v[i-1]) best = 2;
			else if(v[i+1]>v[i] and v[i]>=v[i+2]) best = 2;
			else if(v[i+1]<v[i] and v[i]<=v[i+2]) best = 2;
		}

		cout << tot-best << endl;

	}
	
	
	
	exit(0);
}
