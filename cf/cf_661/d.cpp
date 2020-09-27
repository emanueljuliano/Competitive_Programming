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

#define MAXP 10001000

int id[MAXP];
int sz[MAXP];

int find(int p){
	if (id[p] == p) return p;
	return id[p] = find(id[p]);
}

void join(int p, int q){
	p = find(p);
	q = find(q);
	if (p==q) return;
	if(sz[p] > sz[q]) swap(p, q);
	id[p]=q;
	sz[q]+= sz[p];
	return;
}
void build(int n){
	for(int i=0;i <n; i++) id[i] = i, sz[i] = 1;
}


int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		vector<int> one, zero;
		build(n);
		for(int i=0;i <n; i++){
			int c = s[i]-'0';
			if(c and zero.size()){
				int x = zero.back();
				zero.pop_back();
				join(i, x);
				one.pb(i);
			}
			else if (!c and one.size()){
				int x = one.back();
				one.pop_back();
				join(i, x);
				zero.pb(i);
			}
			else{
				if(c) one.pb(i);
				else zero.pb(i);
			}
		}
		map<int, int> mp;
		int pt = 1;
		for(int i=0; i<n; i++){
			if(!mp.count(find(i))) mp[find(i)] = pt++;
		}
		cout << pt-1 << endl;
		for(int i=0;i <n; i++){
			cout << mp[find(i)] << " ";
		}
		cout << endl;
	}



	exit(0);
}
