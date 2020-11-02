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

const int MAX = 3e4 + 10;
const int MAX2 = 1e6 + 10;
const int bsz = sqrt(MAX) + 1;
int cnt=0;
int n, q;
int v[MAX];
int freq[MAX2];
ii query[(int)2e5 + 10];

bool ord(pair<ii, int> a, pair<ii, int> b){
	if(a.f.f/bsz != b.f.f/bsz) return a.f.f<b.f.f;
	return a.f.s < b.f.s;
}
void insert(int i){
	if(!freq[v[i]]) cnt++;
	freq[v[i]]++;
}
void erase(int i){
	freq[v[i]]--;
	if(!freq[v[i]]) cnt--;
}
vector<int> mo(){
	vector<pair<ii, int>> ev;
	for(int i=0;i <q; i++) ev.pb({query[i], i});
	sort(ev.begin(), ev.end(), ord);
	
	vector<int> ret(q);
	int ini = 0, end = 0;
	insert(0);
	for (auto u : ev){
		int l = u.f.f, r = u.f.s, id=u.s;
		while(end<r) insert(++end);
		while(ini>l) insert(--ini);
		while(end>r) erase(end--);
		while(ini<l) erase(ini++);

		ret[id] = cnt;
	}
	return ret;
}

int main(){ _
	cin>> n;
	for(int i=0;i <n; i++) cin >> v[i];
	
	cin >> q;
	for(int i=0;i <q; i++){
		int a, b; cin >> a >> b; a--, b--;
		query[i] = {a, b};
	}
	vector<int> ans = mo();
	for(auto u : ans) cout << u << endl;

	exit(0);
}
