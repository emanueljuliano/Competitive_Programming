#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
 
using namespace std;
 
typedef long long ll;
 
const int MAX = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
 
int main(){_
 
	int n;
	cin >> n;
	vector<pair<ll ,int> > v(n, make_pair(0, 1));
	for(int i = n-1; i >= 0; i--){
		int x; cin >> x;
		v[i].f = x;
	}
	bool flag = true;
	vector<pair<ll,int> > ans;
	while(flag){
		flag = false;
		ans.clear();
		for(int i = 0; i < v.size(); i++){
			ll sum = v[i].f;
			int qnt = v[i].s;
			int j = i+1;
			ll rs = v[i].f;
			while(j != v.size() and ((v[j].f-rs>0) or (abs(v[j].s-rs)==0))){
				flag = true;
				sum += v[j].f;
				qnt += v[j++].s;
				rs = sum;
			}
			ans.pb({rs, qnt});
			i = j-1;
		}
		v = ans;
	}
	reverse(ans.begin(), ans.end());
	cout << setprecision(9) << fixed;
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].s; j++)
			cout << (double)ans[i].f/ans[i].s << endl;
	}
}
