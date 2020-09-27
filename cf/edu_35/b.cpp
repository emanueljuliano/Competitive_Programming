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

int pd[210][110][110];
int n;
int solve(int m, int a, int b){
	if(m==n and a==0 and b==0) return INF;
	if(m==n) return 0;
	if(a==0 and b==0) return 0;
	int &ret = pd[m][a][b];
	if(ret != -1) return ret;
	ret = 0;

	for(int i=1;i <=a; i++){
		ret = max(ret, min(i, solve(m+1, a-i, b)));
	}
	for(int i=1;i <=b; i++){
		ret = max(ret, min(i, solve(m+1, a, b-i)));
	}
	return ret;
}

int main(){ _
	memset(pd, -1, sizeof(pd));
	int a, b; cin >> n >> a >> b;
	int ans = solve(0, a, b);
	cout << ans << endl;
	
	
	exit(0);
}
