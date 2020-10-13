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
	string s; cin >> s;

	int n = s.size();
	vector<int> v(n);
	for(int i=0;i <n; i++)
		v[i] = s[i]-'0';
	
	stack<int> st;
	vector<int> ans(n+1);
	ans = v;

	st.push(n);
	for(int i=n-1; i+1; i--){
		if(v[i]==0){
			ans[i] = 0;
			st.push(i);
		}
		else if(v[i]==1){
			ans[i] = 1;
		}
		while(v[i]>1){	
			int z = st.top();
			int d = z-i;
			if(v[i]-1 <= d){
				if(i) v[i-1] += v[i]-1;
				if(z!=n) st.pop();
				ans[z] = 1;
				ans[z-v[i]+1] = 0;
				st.push(z-v[i]+1);
				ans[i] = (v[i]-1!=d);
				v[i] = (v[i]-1!=d);
			}
			else{
				st.pop();
				ans[z] = 1;
				ans[i] = 1;
				if(i) v[i-1] += d;
				v[i] -= d+1;
			}
		}
	}
	for(int i=0;i <n; i++) cout << ans[i];
	cout << endl;
	
	
	exit(0);
}
