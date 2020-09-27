#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n; cin >> n;
	map<int, queue<int>> mp;
	for(int i=0;i <n; i++){
		int a; cin >> a; mp[a].push(i);
	}
	int ans = n;
	bool flag = true;
	while(mp.size()==6){
		int at = -1;
		for(auto &u : mp){
			while(u.s.size() and u.s.front() <=at) u.s.pop();
			if(u.s.size()) at = u.s.front(), u.s.pop();
			else flag=false;
		}
		if(!flag) break;
		ans -= 6;
	}
	cout << ans << endl;
	
	
	
	exit(0);
}
