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
		int n; cin >> n;
		int a, b; cin >> a >> b;

		bool flag = true;
		if(b>a) flag = false;
		for(int i=0;i <n-1; i++){
			int a2, b2; cin >> a2 >> b2;
			if(b2>a2) flag = false;
			if(a2<a) flag = false;
			if(b2<b) flag = false;
			b = b2;
			a = a2;
		
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
