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
const int MAX = 2e5+10;

int M[MAX][202];
vector<int> IT[202];
vector<int> v;
int n;
int solve(int a, int b){
	vector<int> w;
	int ips = 0;
	for(int i=0;i <n; i++){
		if(v[i]==a or v[i]==b) w.pb(v[i]);
		if(v[i]==b) ips++;
	}

	int m = w.size();
	int x = 0, y = ips;
	int ret = 0;
	int i = 0, it= m-1;
	//cout << "Vez de " << a << "  " << b << endl;
	//for(auto k : w ) cout << k << " ";
	//cout << endl;

	while(true){
		while(i<m and w[i]!=a)i++, y--;
		while(it>=0 and w[it]!=a) it--, y--;
		x++;
		if(i>=it) break;
		ret = max(ret, 2*x + y);
		i++;
		it--;
	}
	//cout << "R " << ret << endl;
	//cout << endl;
	return ret;

}

int main(){ _
	int t; cin >> t;
	while(t--){
		v.resize(0);
		for(int i=0;i <=200; i++) IT[i].resize(0);
		vector<int> show(202, 0);
		
		cin >> n;
		
		for(int i=0; i<n; i++) 
		{
			int a; cin >> a;
			v.pb(a);
			IT[a].pb(i);
			show[a]++;
			for(int j=1;j <=200; j++) M[i][j] = show[j];
		}

		int ans = 1;
		for(int k=0;k <=200; k++){
			int m = IT[k].size();
			
			if(m<2) continue;
			for(int i=0;i <m/2; i++){

				int x = i+1, y = 0;
				int it1 = IT[k][i];
				int it2 = IT[k][m-1-i];
			//	cout << "--------A= " << k<< endl;
			//	cout << "it1 = " << it1 << " it2 = " << it2 << endl;
				for(int j=1;j <=200; j++){
					int yy =  M[it2-1][j] - M[it1][j];
					y = max(y, yy);
			//		if(yy!=0)cout << "B = " << j << " x = "<< x << " y =" << yy << endl;
				}
			//	cout << "------------" << endl;
			//	cout << endl;
				ans = max(ans, 2*x+y);
			}
		}
		/*
		for(auto i : st){
			int x = mst.count(i);
			ans = max(ans, x);
			for(auto j : st){
				if(i==j) continue;
				ans = max(ans, solve(i, j));
			}
		}
		*/
		cout << ans << endl;

	
	
	}
	
	
	
	exit(0);
}
