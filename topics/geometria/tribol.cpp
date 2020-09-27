#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x.size())
#define pb push_back
#define s second
#define f first
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define sq(x) ((x)*(x))

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ld eps = 1e-9;

int main(){ _
	int t; cin >> t;
	map<char, int> ma;
	ma['R'] = 0;
	ma['G'] = 1;
	ma['B'] = 2;

	while(t--){
		int n; cin >> n;
		int ans[3] = {0, 0, 0};
		for(int i=0; i<n; i++){
			char a, b; cin >> a >> b;
			int x= ma[a],y = ma[b];
			if(y == (x+1)%3) ans[x]+=2;
			else ans[x]++;
		}
		int maxi = max(ans[0], max(ans[1], ans[2]));
		int bora=0;
		for(int i=0; i<3; i++) if(ans[i]==maxi) bora++;
		if (bora==3){
			cout << "trempate" << endl;
		}
		else if(bora==2){
			cout << "empate" << endl;
		}
		else{
			if(ans[0]==maxi) cout << "red" << endl;
			else if(ans[1]==maxi) cout << "green" << endl;
			else cout << "blue" << endl;
		}
	}

	exit(0);
}
