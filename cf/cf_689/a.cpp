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
		int n, k; cin >> n >> k;
		for(int i=0;i <n; i++){
			if(i%3==0) cout << 'a';
			if(i%3==1) cout << 'b';
			if(i%3==2) cout << 'c';
		}
		cout << endl;
	}
	
	
	
	exit(0);
}
