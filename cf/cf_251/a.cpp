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
	int n, d; cin >> n >> d;
	int sum = 0;
	int ans = 0;
	int tot=0;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		sum+=a;
		tot+=a;
		if(i!=n-1) sum+=10, ans+=2;
	}
	if(sum>d) cout << -1 << endl;
	else cout << (d-tot)/5 << endl;

	
	
	exit(0);
}
