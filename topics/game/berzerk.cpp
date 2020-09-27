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


int ent[7010][2];
int dp[7010][2];
int K[2];
vector<int> v, w;
int n;
bool flag = true;
void solve(int p, int at, int prev){
	if(dp[p][at]!=-1) return;
	if(p==0 and !flag) return;
	if(prev==0) {
		dp[p][at] = 1;
		if(at==1){ for(auto k : v) solve((p-k+n)%n, !at, 1);}
		else{ for(auto k : w) solve((p-k+n)%n, !at, 1);}
		return;
	}
	ent[p][at]++;
	
	if(ent[p][at]==K[at] or flag){
		flag = false;
		dp[p][at]=0;
		if(at==1){ for(auto k : v) solve((p-k+n)%n, !at, 0);}
		else{ for(auto k : w) solve((p-k+n)%n, !at, 0);}		
	}
	return;
}

int main(){ _
	memset(dp, -1, sizeof(dp));
	memset(ent, 0, sizeof(ent));
	cin >> n;
	int k; cin >> k; K[0]=k;
	for(int i=0;i <k; i++){int a; cin >> a; v.pb(a);}
	cin >> k; K[1]=k;
	for(int i=0;i <k; i++){int a; cin >> a; w.pb(a);}
	
	solve(0, 1, 1);
	flag = true;
	solve(0, 0, 1);

	for(int i=1; i<n; i++){
		int a = dp[i][0];
		if(a==-1) cout << "Loop ";
		else if(a==0) cout << "Lose ";
		else cout << "Win ";
	}	
	cout << endl;
	for(int i=1; i<n; i++){
		int a = dp[i][1];
		if(a==-1) cout << "Loop ";
		else if(a==0) cout << "Lose ";
		else cout << "Win ";
	}	
	cout << endl;

	
	exit(0);
}
