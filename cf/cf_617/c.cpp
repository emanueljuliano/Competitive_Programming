#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t; cin >>t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int L, R, U, D;
		L = R = U = D = 0;
		int at = 0;
		int mini = 1000000;
		int ans1=-1, ans2=-1;
		map<pair<int, int>, int> se;
		pair<int, int> aux = {0, 0};
		se[aux] = -1;
		int x=0, y=0;
		for(int i=0; i<n; i++){
			if(s[i]=='L') x--;
			if(s[i]=='R') x++;
			if(s[i]=='U') y++;
			if(s[i]=='D') y--;
			pair<int, int> pa = {x, y};
			if(se.count(pa)){
//				cout << i << " " << se[pa] << endl;
//				cout << pa.first << " " << pa.second << endl;
				if(i-se[pa] < mini){
					mini = i-se[pa];
					ans1 = se[pa]+2;
					ans2 = i+1;
				}
			}
			se[pa] = i;
		}
		if(ans1==-1) cout << -1 << endl;
		else cout << ans1 << " " << ans2 << endl;
	}


	exit(0);
}
