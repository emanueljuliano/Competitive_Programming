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
int n;
int solve(vector<int> v){
	bool show = true;
	int mov = 0;
	for(int i=0;i <v.size()-1; i++){
		int g = gcd(v[i], v[i+1]);
		if(g!=1){ mov++;	
			vector<int> w = v;
			w[i]/=g, w[i+1]/=g;
			show &= solve(w);
		}
	}
	return mov and !show;
}

int main(){ _
	cin >> n;
	vector<int> v(n);
	for(auto &i: v) cin >> i;
	
	if(solve(v)) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	
	
	exit(0);
}
