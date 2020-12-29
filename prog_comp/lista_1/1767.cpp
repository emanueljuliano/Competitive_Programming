#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define s second
#define f first

typedef long long ll;
typedef pair<int, int> ii;

vector <ii> v;
int n;
pair<ii, int> pd[110][53];
pair<ii, int> null = {{-1, -1}, -1};

pair<ii, int> rec(int pes, int x){
	if(x>=n)
		return {{0, 0}, 0};
	
	if(pd[x][pes] !=  null) return pd[x][pes];
	
	ii at = v[x];

	if(at.s > pes)
		return pd[x][pes] = rec(pes, x+1);
	
	
	pair<ii, int> q1, q2;
	q1 = rec(pes-at.s, x+1);
	q1.f.f += at.f;
	q1.f.s += at.s;
	q1.s++;

	q2 = rec(pes, x+1);

	if(q1.f.f > q2.f.f)
		return pd[x][pes] = q1;
	return pd[x][pes] = q2;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		v.resize(0);
		cin >> n;
		for(int i=0; i<n; i++) for(int j=0; j<=50; j++) pd[i][j] = null;
		
		for(int i=0; i<n; i++){
			int a, b; cin >> a >> b;
			v.pb({a, b});
		}
		pair<ii, int> ans = rec(50, 0);
		cout << ans.f.f << " brinquedos" << endl;
		cout << "Peso: " << ans.f.s << " kg" << endl;
		cout << "sobra(m) " << n-ans.s << " pacote(s)" << endl;
		cout << endl;
	}
	exit(0);
}
