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


bool check(vector<vector<int>> M){
	bool ret = true;
	for(int i=0;i <9; i++){
		bool flag = false;
		vector<int> dis(10, 0);
		for(int j=0;j <9; j++){
			dis[M[i][j]]++;
		}
		for(int j=1; j<=9; j++) if(dis[j]==0 or dis[j]>1) flag = true;
		if(!flag) return false;

	}
	for(int j=0;j <9; j++){
		vector<int> dis(10, 0);
		bool flag = false;
		for(int i=0;i <9; i++){
			dis[M[i][j]]++;
		}
		for(int i=1; i<=9; i++) if(dis[i]==0 or dis[i]>1) flag = true;
		if(!flag) return false;
	}
	for(int k=0;k <9; k++){
		vector<int> dis(10, 0);
		bool flag = false;
		for(int i=0;i <3; i++){
			for(int j=0;j <3; j++){
				dis[M[k/3+i][3*(k%3)+j]]++;
			}
		}
		for(int i=1; i<=9; i++) if(dis[i]==0 or dis[i]>1) flag = true;
		if(!flag) return false;
	}
	return true;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		vector<vector<int>> M(9), M2;
		for(int i=0;i <9; i++){
			string s; cin >> s;
			for(int j=0; j<9; j++){
				M[i].pb(s[j]-'0');
			}
		}

		vector<int> li;
		vector<int> co;
		for(int i=0;i <9; i++) li.pb(i), co.pb(i);
		/*
		while(true){
			M2 = M;
			random_shuffle(li.begin(), li.end());
			random_shuffle(co.begin(), co.end());
			
			for(int i=0;i <9; i++){
				M2[li[i]][co[i]] = M[li[(i+1)%9]][co[(i+1)%9]];
			}
			if(check(M2)){
				for(int i=0;i <9; i++){
					for(int j=0;j <9; j++) cout << M2[i][j];
					cout << endl;
				}
				break;
			}
		}
		*/
		M[0][0]++;
		M[3][1]++;
		M[6][2]++;
		M[1][3]++;
		M[4][4]++;
		M[7][5]++;
		M[2][6]++;
		M[5][7]++;
		M[8][8]++;
		for(int i=0;i <9; i++){
			for(int j=0;j <9; j++){
				cout << 1+(M[i][j]-1)%9;
			}
			cout << endl;
		}
	}
	
	
	
	exit(0);
}
