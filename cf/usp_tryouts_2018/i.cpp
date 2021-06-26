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

vector<ii> ans;
void solve(int n, int a, int b, int c){
	if(n==1){
		ans.pb({a, c});
		return;
	}
	solve(n-1, a, c, b);
	ans.pb({a, c});
	solve(n-1, b, a, c);
}

int main(){ _
	int n, k; cin >> n >> k;
	if(k<(1<<n)-1) {
		cout << "N" << endl;
		return 0;
	}
	solve(n, 0, 1, 2);

	cout << "Y" << endl;
	while(k-2 >= int(ans.size())) cout << "A B" << endl << "B A" << endl, k-=2;
	if(k==ans.size()){
		for(auto [a, b] : ans) cout << char(a+'A') << " " << char(b+'A') << endl;
	}
	else{
		for(int i=0;i <ans.size()-1; i++) 
			cout << char(ans[i].f+'A') << " " << char(ans[i].s+'A') << endl;
		int no=0;
		while(no==ans.back().f or no==ans.back().s) no++;
		cout << char(ans.back().f+'A') << " " << char(no+'A') << endl;
		cout << char(no+'A') << " " << char(ans.back().s + 'A') << endl;
	}

	exit(0);
}
