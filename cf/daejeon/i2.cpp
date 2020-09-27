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
	int n; cin >> n;
	vector<int> v;
	for(int i=0;i <n; i++){
		int a; cin >> a; v.pb(a);
	}
	int k = n-1, p=1;
	int pa=1;
	vector<int> dp(n+10, 1);
	for(int i=n-2; i>=0; i--){
	//	cout << i << " " << pa << endl;
		if(v[i] != v[i+pa]){
	//		cout << "UE" << endl;
			int at = pa;
			bool flag = true;
			while(flag){
				at++;
		//		cout << at << endl;
				if((i+at == n) or (v[i]==v[i+at] and __gcd(at, pa)==dp[i+at])){
					dp[i] = at;
					pa = at;
					flag = false;
				}
			}
		}	
		dp[i] = pa;
		if(i+pa < k+p){
			k = i;
			p = pa;
		}
	}
	cout << k << " " << p << endl;
	
	
	exit(0);
}

