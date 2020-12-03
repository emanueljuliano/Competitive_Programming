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


int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;

		bool show = false;
		int a, b, c;
		for(int i=0;i <=n/7; i++){
			for(int j=0; j<=n/5; j++){
				if((n-i*7-j*5)%3==0){
					a=i, b=j, c=(n-i*7-j*5)/3;
					show = true;
				}
				if(show) break;
			}
			if(show) break;
		}
		if(show) cout << c << " " << b << " " << a << endl;
		else cout << -1 << endl;
	}
	
	
	
	exit(0);
}
