#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

bool solve(vector<vector<int>> M, int at, bool print=false){
	if(at==0) {
		if(print) {for(auto u : M){
			for(auto c : u) cout << c;
			cout << endl;
			}
			cout << endl;
		}
		return true;
	}
	bool ret = false;
	for(int i=0; i<M.size()-at+1; i++){
		for(int j=0; j<M[0].size()-at+1; j++){
			vector<vector<int>> M2 = M;
			bool b = false;
			for(int ii=i; ii<i+at; ii++) {
				for(int jj=j; jj<j+at; jj++){
					if(M2[ii][jj] == 1) {b = true; break;}
					else M2[ii][jj] = 1;
				}
				if(b) break;
			}
			if(!b) ret |= solve(M2, at-1, print);
		}
	}
	return ret;
};

int main(){ _
	int n, m;
	cin >> n >> m;
	vector M(n, vector(m, 0));

	int last = 0;
	for(int i=1; i<=10; i++){
		if(solve(M, i)) last = i;
		else break;
	}
	//solve(M, last, 1);
	cout << last << endl;
	int sum = 0;
	//for(int i=1; i<=last; i++) sum += i*i;
	//cout << n*m << " " << sum << " " << sum+(last+1)*(last+1) << endl;
	exit(0);
}
