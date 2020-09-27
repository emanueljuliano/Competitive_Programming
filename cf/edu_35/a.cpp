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
	vector<int> v(n);
	for(auto &i : v) cin >> i;
	vector<int> w(n, 0);
	int mini = INF;
	for(int i=0;i <n; i++) if(v[i]<mini) mini = v[i];
	for(int i=0;i <n; i++){
		if(v[i]==mini) w[i] = 1;
	}
	int at = (int)1e6;
	int ans = (int)1e6;
	for(int i=0;i <n; i++){
		if(w[i]){
			ans =  min(ans, at);
			at = 0;
		}
		at++;
	}
	cout << ans << endl;
	
	
	
	exit(0);
}
