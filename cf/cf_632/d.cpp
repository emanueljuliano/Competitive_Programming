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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<vector<int>> ans;
	int tot=0;
	while(true){
		vector<int> t;
		for(int i=0;i <s.size()-1; i++){
			if(s[i]=='R' and s[i+1]=='L'){
				s[i] = 'L';
				s[i+1] = 'R';
				t.pb(i);
				tot++;
				//cout << i << endl;
				i++;
			}	
		}
		if(t.size()==0) break;
		ans.pb(t);
	}
	if(ans.size()>k or tot<k) return cout << -1 << endl, 0;
	int sz = ans.size();
	int ii = 0, jj=0;
	while(k>sz){
		cout << "1 " << ans[ii][jj]+1 << endl;
		jj++;
		k--;
		if(jj==ans[ii].size()) sz--, jj=0, ii++; 
	}

	cout << ans[ii].size()-jj <<" ";
	for(int i=jj; i<ans[ii].size(); i++) cout << ans[ii][i]+1 << " ";
	cout << endl;
	sz--;

	for(int i=ans.size()-sz; i <ans.size(); i++){
		cout << ans[i].size() << " ";
		for(int j=0; j<ans[i].size(); j++) cout << ans[i][j]+1 << " ";
		cout << endl;
	}
	
	exit(0);
}
