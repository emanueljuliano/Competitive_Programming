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
const int N = 1e5 + 10;

int main(){ //_
	int t; cin >> t;
	int out = 0;
	while(out<t){
		out++;
		int n, k; cin >> n>> k;
		multiset<string> st;
		for(int i=0;i <n; i++){
			string a; cin >> a;
			st.insert(a);
		}
		int ans = 0;
		cout << "HM" << endl;
		while(!st.empty()){
			string at = *st.rbegin();
			int c = st.count(at);
			st.erase(at);
			if(c>=k){
				ans += at.size();
				for(int i=0; i<c-k; i++)
					st.insert(at);
			}
			else{
				if(at.size()==1) continue;
				at.pop_back();
				for(int i=0; i<c; i++)
					st.insert(at);
			}
		}	
		
		cout << "Case #" << out << ": " << ans << endl;
	}
	exit(0);
}
