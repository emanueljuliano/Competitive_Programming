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

const int MAX = 1e3+10;
int dp[MAX];
int n, c, t1, t2;
int fim;
vector<int> v;
int solve(int at){
	if(at==n) return 0;
	int &ret = dp[at];
	if(ret!=-1) return ret;

	int at1=at;
	while(at1<n and v[at1]<=v[at]+t1) at1++;
	ret = t1+solve(at1);
	
	int at2=at;
	while(at2<n and v[at2]<=v[at]+t2) at2++;
	ret = min(ret, t2+solve(at2));

	return ret;
}

int main(){ _
	cin >> n >> c >> t1 >> t2;		
	
	v.resize(n);
	for(auto &i:v) cin >> i;
	
	int ans = INF;
	for(int i=0;i <n; i++){
		vector<int> w;
		for(int j=i; j<n+i; j++) w.pb((v[j%n]-v[i]+c)%c);
		for(int j=0; j<=n; j++) dp[j] = -1;
		v = w;
		ans = min(ans, solve(0));
	}
	cout << ans << endl;

	exit(0);
}
