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

unordered_map<int, vector<int>> M;
int n;

const int MAX = 1e5+10;
const int SQ = sqrt(MAX);
int v[MAX];

int ans, freq[MAX];

void insert(int p){
	int o = v[p];
	freq[o]++;
	ans += (freq[o] == 1);
}
void erase(int p){
	int o = v[p];
	ans -= (freq[o] == 1);
	freq[o]--;
}

vector<int> MO(vector<ii> &q){
	ans = 0;
	memset(freq, 0, sizeof freq);
	int m = q.size();
	vector<int> ord(m), ret(m);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int l, int r){
		int sl = q[l].first/SQ;
		int sr = q[r].first/SQ;
		if (sl != sr) return sl < sr;
		return q[l].second < q[r].second;
	});
	int l = 0, r = 0;
	insert(0);
	
	for (int i : ord){
		int ql, qr;
		tie(ql, qr) = q[i];
		while (r < qr) insert(++r);
		while (l > ql) insert(--l);
		while (l < ql) erase(l++);
		while (r > qr) erase(r--);
		ret[i] = ans;
	}
	return ret;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		
		M.clear();
		cin >> n;
		vector<ii> q;
		
		for(int i=0; i<n; i++){
			int a; cin >> a;
			v[i] = a;
			M[a].pb(i);
		}

		for(auto aux : M){
			for(int j=0; j<aux.s.size()/2; j++){
				int it = aux.s.size()-1-j;
				q.pb({aux.s[j]+1, aux.s[it]-1});
			}
		}
		vector <int> w = MO(q);

		
		int it = 0;		
		int ans = 1;
		for(auto aux : M){
			ans = max(ans, (int)aux.s.size());
			int x = 0;
			int y = 0;
			for(int j=0; j<aux.s.size()/2; j++){
				x++;
				y = w[it];
				ans = max(ans, 2*x+y);
			
				cout << "Querys de " << aux.f << endl;
				cout << q[it].f << " " << q[it].s << " freq = " << w[it] << endl;
				it++;
			}
		}
	


		cout << ans << endl;

	
	
	}
	
	
	
	exit(0);
}
