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

string M[2200];
int n;
map<string, int> ma;
map<string, vector<ii>> nxt;
ii pd[2100][2100];

bool cmp(ii a, ii b){
	if (a.s == b.s) return a.f > b.f;
	return a.s > b.s;
}


ii rec(int at, int g){
//	cout << "rec = " << M[at] << " " << at << " " << g << endl;

	if(g<0) return {-1, -1};
	
	ii &ans = pd[at][g];
	if(g==0 and at==n) return ans = {-1, 0};
	if(at==n and g!=0) return ans = {-1, -1};
	if(ans.f != -2 and ans.s!= -2) return ans;
	
	vector<ii> v = nxt[M[at]];
	sort(v.begin(), v.end(), cmp);
	
	for(auto pos : v){
//		cout << "pos = " << pos.f << " " << pos.s  << endl;
		if(rec(at+1, g-pos.f).s != -1){
			return ans = pos;
		}
	}
	return ans = {-1, -1};
}

int main(){ _
	int  k; cin >> n >> k;
	for(int i=0;i <=n; i++){
		for(int j=0;j <=k; j++)
			pd[i][j] = {-2, -2};
	}
	vector<string> aux = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	set<string> st;
	for(int i=0;i <=9; i++){
		st.insert(aux[i]);
		ma[aux[i]] = i;
	}
	for(int i=0;i <1<<7; i++){
		string s;
		for(int j=0; j<7; j++){
			if(1<<j & i)s.pb('1');
			else s.pb('0');
		}
	//	cout << s << endl;
		for(int j=0; j< 1<<7; j++){
			string s2;
			if(!(j&i)){
				for(int k=0; k<7; k++){
					if((1<<k & i) or (1<<k & j))s2.pb('1');
					else s2.pb('0');
				}
				if(st.count(s2)) nxt[s].pb({__builtin_popcount(j), ma[s2]});
			}
		}
	}


	for(int i=0;i <n; i++){
		cin >> M[i];
	}
	vector<int> ans;
	for(int i=0;i <n; i++){
		ii at = rec(i, k);
		if(at.s == -1) break;
		k-=at.f;
		ans.pb(at.s);
	}
	if(ans.size()!=n) cout << -1 << endl;
	else{
		for(auto x : ans) cout << x;
		cout << endl;
	}
	exit(0);
}
