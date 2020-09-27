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
int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(vector<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
}


int main(){ _
	crivo(MAX-5);
	int n; cin >> n;
	vector<int> v;
	vector<vector<int>> fat(n);
	map<int, int> pri;
	for(int i=0; i<n; i++){
		int a; cin >> a; v.pb(a);
		fact(fat[i], a);
		sort(fat[i].begin(), fat[i].end());
		int at = -1;
		for(int j=0;j <fat[i].size(); j++) {
			if(at!=fat[i][j]) at = fat[i][j], pri[at]++;
		}
	}
	ll ans = 1;
	for(auto x : pri){
		if(x.s==n or x.s==n-1){ // segundo
			int mini = INF, mini2 = INF+1;
			for(int i=0; i<n; i++){
				int range = upper_bound(fat[i].begin(), fat[i].end(), x.f) - lower_bound(fat[i].begin(), fat[i].end(), x.f);
				if(range<mini){
					mini2 = mini;
					mini = range;
				}
				else if(range<mini2){
					mini2 = range;
				}
			}
			for(ll i =0 ; i<mini2; i++){
				ans*=(ll)x.f;
			}
		}
	}
	cout << ans << endl;	



	exit(0);
}
