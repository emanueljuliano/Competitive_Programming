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
		return true;
	}
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
			if(!b) return solve(M2, at-1, print);
		}
	}
	return false;
};

int main(){ _
	int n, m;
	cin >> n >> m;
	//if(n>m) swap(n, m);
	vector M(n, vector(m, 0));
	
	int last = 0;
	for(int i=1; i<=30; i++){
		if(solve(M, i)) last = i;
		else break;
	}
	cout << last << endl;	
	exit(0);
}
