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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

vector<ii> from_prufer(vector<int> p){
	int n = p.size()+2;
	vector<int> d(n, 1);
	for(int i : p) d[i]++;
	p.pb(n-1);
	int idx, x;
	idx = x = find(d.begin(), d.end(), 1) - d.begin();
	vector<ii> ret;
	for(int y : p){
		ret.pb({x, y});
		if(--d[y] == 1 and y < idx) x = y;
		else idx = x = find(d.begin()+idx+1, d.end(), 1) - d.begin();
	}
	return ret;
}

int main(int argc, char**argv){ _
	srand(atoi(argv[1]));
	
	int mx = 5;
	int n = rand()%mx+2;

	cout << n << endl;
	for(int i=0;i <n; i++){
		cout << rand()%2 << " ";
	}
	cout << endl;

	vector<int> v(n-2);
	for(auto &i : v) i = rand()%n;
	
	vector<ii> eg = from_prufer(v);
	for(auto [a, b] : eg) cout << a+1 << " " << b+1 << endl;
	
	exit(0);
}
