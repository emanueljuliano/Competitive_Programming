#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n;
	cin >> n;
	vector<int> v;
	for(int i=0; i<n; i++){
		int a; cin>>a;
		v.pb(a);
	}
	vector<int> f;
	vector<int> s;
	int it=1e6;
	for(int i=0; i<n; i++){
		if(v[i]==0){
			it = 0;
		}
		f.pb(it);
		it++;
	}
	it = 1e6;
	for(int i=n-1; i>=0; i--){
		if(v[i]==0){
			it = 0;
		}
		s.pb(it);
		it++;
	}
	reverse(s.begin(), s.end());
	vector<int> ans;
	for(int i=0; i<n; i++){
		ans.pb(min(f[i], s[i]));
	}
	for(int i=0; i<n; i++)
		cout << ans[i] << " ";
	cout << endl;

	exit(0);
}
