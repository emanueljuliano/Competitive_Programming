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


int main(){ _
	int n; cin >> n;
	vector<int> v(n), w(n);
	for(int i=0;i <n; i++){
		cin >> v[i];
	}
	int dist = INF;
	for(int i=0;i <n; i++){
		if(v[i]==0) dist=0;
		w[i] = dist;
		dist++;
	}
	dist = INF;
	for(int i=n-1;i+1; i--){
		if(v[i]==0) dist=0;
		w[i] = min(w[i], dist);
		dist++;
	}
	for(auto x : w) cout << x << " ";
	cout <<endl;

	
	
	
	exit(0);
}
