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

const int MAX = 1e6+10;
vector<vector<int>> g(MAX);
int dis[MAX], comp[MAX];
vector<int> w;

int bfs(int x){
	for(int i=0;i <w.size(); i++)
		dis[w[i]]=-1;
	
	queue<ii> q;
	q.push({x, x});
	dis[x] = 0;
	int ret = INF;
//	cout << "BFS DE " << x << endl;
//	for(int i=0;i <g[x].size(); i++) cout << g[x][i] << " ";
//	cout <<endl;
	
	while(!q.empty()){
		ii aux = q.back(); q.pop();
		int v = aux.f;
//		cout << v << " " << dis[v] << endl;

		if(v!=x and comp[x] and comp[v]) ret = min(ret, 2+dis[v]);
//		cout << x << " comp= " << comp[x] << " " << v << " comp= " << comp[v] << endl;
		for(int i=0;i <g[v].size(); i++){
			int vv = g[v][i];
			if(vv!=x and comp[x] and comp[vv]) ret = min(ret, 2+dis[v]+1);
			if(vv==aux.s) continue;
			if(dis[vv]==-1){
				q.push({vv, v}); dis[vv] = dis[v]+1;
			}
			else{
		//		cout << vv << endl;
//				cout << v << " dis = " << dis[v] << " visto " << vv << " dis= " << dis[vv] << endl;
				ret = min(ret, dis[v] + dis[vv]+1);
			}
		}
	}

	if(ret==INF) return -1;
	return ret;
}

int main(){ _
	memset(comp, 0, sizeof(comp));
	int n; cin >> n;
	vector<int> v, pri;
	while(n--){
		ll a; cin >> a;
		int div1= 0, div2=0;
		int mant = a;
		for(ll i=2; i*i<=a; i++)if(a%i==0){
			while(a%i==0) a/=i;

			if(div1) div2 = i;
			else div1 = i;
			
		}
		if(a!=1){
			if(div1) div2 = a;
			else div1=a;
		}
		
		if(div2) {
			if(!g[div1].size()) w.pb(div1);
			if(!g[div2].size()) w.pb(div2);
			g[div1].pb(div2);
			g[div2].pb(div1);
		}
		//cout << div1 << " " << div2 << endl;
		if(div2){
			v.pb(div1*div2);
			comp[div1*div2]++;
		}
		else{
			pri.pb(div1);
		}
		a = mant;
		ll x=div1, y=div2;

		bool flag = false;
		if(a==1 or x*x==a) flag = true;
		if(x*x <MAX and x*x*x*x==a) flag = true;
		if(x*x*x<MAX and (x*x*x*x*x*x==a or x*x*x*x*x*x*x*x==a)) flag = true;
		if(x*y<MAX and (x*y*x*y==a or x*y*x*y*x*y==a)) flag = true;
		if(flag) return cout << 1 << endl, 0;
	}

	sort(v.begin(), v.end());
	if(!v.empty())for(int i=0;i <v.size()-1; i++) if(v[i]==v[i+1]) return cout << 2 << endl, 0;
	
	if(!pri.empty()) {
		sort(pri.begin(), pri.end());
		for(int i=0;i <pri.size()-1; i++) if(pri[i]==pri[i+1]) return cout << 2 << endl, 0;
		for(int i=0;i <pri.size(); i++){
			comp[pri[i]]++;
			for(int j=0;j<pri.size(); j++){
				ll at = ll(pri[i])*pri[j];
				if (at>MAX) break;
				if(comp[at]) return cout << 3 << endl, 0;
			}
		}
	}

	sort(w.begin(), w.end());
	int ans = -1;
	if(!w.empty()){
		for(int i=0;i <w.size(); i++){
			if(ll(w[i])*w[i]>MAX) break;
				int b = bfs(w[i]);
				if(b!=-1) ans = min(b, ans);
				if(ans==-1) ans = b;
	//			cout << i<< " no fim deu " << b<< endl;
		}
	}
	
	 cout << ans << endl;
	
	exit(0);
}
