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
	freopen("powers.in", "r", stdin);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int ans = 0;
		for(int i=0;i <n; i++){
			int a, b; cin >> a >> b;
			if(a%2) ans ^= (b%2);
			else{
				if((b+1)%(a+1) == 0) ans ^= 2;
				else{
					if(b+1<a+1) ans ^= (b%2);
					else{
						int x = (b+1)/(a+1);
						b -= x*(a+1);
						ans ^= (b%2);
					}
				}
			}
		}
		if(ans==0) cout << 2 << endl;
		else cout << 1 << endl;
	}	

	
	
	exit(0);
}
