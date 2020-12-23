#include <bits/stdc++.h>

using namespace std;

#define debbuging true
#define debug if(debbuging) cout
#define _ if(!debbuging) ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int h; cin >> h;
	vector<int> v(h+1);
	int n = 0;
	for(auto &i : v) cin >> i, n+=i;
	bool show = false;
	for(int i=0;i <h; i++) if(v[i]!=1 and v[i+1]!=1) show = true;
	if(!show) return cout << "perfect" << endl, 0;

	vector<int> v1(n);
	for(int i=1;i <=h; i++) v1[i] = i;
	int it = h+1;
	for(int i=1;i <=h; i++) for(int j=0; j<v[i]-1; j++) v1[it++] = i;

	vector<vector<int>> part(h+1);
	vector<int> v2(n);
	part[0].pb(0);
	it = 1;
	for(int i=1;i <=h; i++) for(int j=0; j<v[i]; j++) 
		v2[it] = part[i-1][j%v[i-1]]+1, part[i].pb(it++);

	cout << "ambiguous" << endl;
	for(auto u : v1) cout << u << " ";
	cout << endl;
	for(auto u : v2) cout << u << " ";
	cout << endl;



	exit(0);
}
