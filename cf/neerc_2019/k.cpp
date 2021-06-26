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
	int n, k; cin >> n >> k;
	int tot = 0;
	vector<int> v(n);
	for(auto &i : v) cin >> i, tot+=i;
	if(tot%k) return cout << "No" << endl, 0;

	int at = 0, ant=-1;
	vector<int> ans;
	for(int i=0;i <n; i++){
		if(at+v[i]>tot/k){
			return cout << "No" << endl, 0;
		}
		else if(at+v[i]==tot/k){
			ans.pb(i-ant), ant=i;
			at = 0;
		}
		else{
			at+=v[i];
		}
	}

	cout << "Yes" << endl;
	for(auto u : ans) cout << u << " ";
	cout << endl;
	
	
	
	exit(0);
}
