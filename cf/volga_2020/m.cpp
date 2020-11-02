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


int main(){ _
	int n; cin >> n;
	vector<vector<int>> row_ans, col_ans;
	
	// bruta no 0 depois no 1 para o x
	for(int b=0; b<2; b++) for(int i=1; (1<<i) <=n; i++){
		vector<int> row, col;
		for(int x=1; x<=n; x++)
			if(!!(x & (1<<i)) == b) row.pb(x);
		for(int y=1; y<=n; y++)
			if(!!(y & (1<<i)) != b and !!((y+1) & (1<<i)) != b) col.pb(y);
		if(!row.empty() and !col.empty())
			row_ans.pb(row), col_ans.pb(col);
	}
	
	// bruta no sufixo da forma pref-011..1
	for(int i=1;(1<<i)-1 <= n; i++){
		int suf = (1<<i) - 1;
		vector<int> row, col;
		for(int y = 1; y<=n; y++)
			if((y&suf) == suf and !(y & (1<<i)))
				col.pb(y);
		for(int x = 1; x<=n; x++){
			if((x&suf) == suf and !(x & (1<<i))) continue;
			if(((x-1)&suf) == suf and !((x-1) & (1<<i))) continue;
			row.pb(x);
		}
		if(!row.empty() and !col.empty())
			row_ans.pb(row), col_ans.pb(col);
	}

	cout << row_ans.size() << endl;
	for(int i=0;i <row_ans.size(); i++){
		cout << row_ans[i].size() << " ";
		for(auto u : row_ans[i]) cout << u << " ";
		cout << endl;
		cout << col_ans[i].size() << " ";
		for(auto u : col_ans[i]) cout << u << " ";
		cout << endl;

	}

//	int M[100][100];
//	for(int i=0; i<row_ans.size(); i++)
//		for(auto u : row_ans[i]) for(auto w : col_ans[i])
//			M[u-1][w-1] = 1;
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++) cout << M[i][j] << " ";
//		cout << endl;
//	}

	exit(0);
}
