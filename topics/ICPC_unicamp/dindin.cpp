#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define pb push_back
#define f first
#define s second
#define BUFF ios::sync_with_stdio(false);

typedef long double ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int MAX = (int)1e5+10;

int main(){

  BUFF;

  double n, m; cin >> n >> m;

  vector<ll> saldo(n, 0);

  while( m-- ){
	  double a, b; cin >> a >> b; a--, b--;
	  ll w; cin >> w;
	  saldo[a] += w;
	  saldo[b] -= w;
  }

  vector<pair<double, ll>> deve, recebe;

  for( int i=0; i<n; i++ ){
	  if( saldo[i] < 0 ){
		  recebe.pb({i, -saldo[i]});
	  }
	  if( saldo[i] > 0 ){
		  deve.pb({i, saldo[i]});
	  }
  }

  int l=0, r=0;

  map<pair<double, double>, ll> art;

  while( l<deve.size() and r<recebe.size() ){

	  ll mn = min(deve[l].s, recebe[r].s);

	  deve[l].s -= mn;
	  recebe[r].s -= mn;

	  art[{deve[l].f, recebe[r].f}] += mn;

	  if( deve[l].s == 0 ){
		  l++;
	  }
	  if( recebe[r].s == 0 ){
		  r++;
	  }
  }

  cout << art.size() << endl;
  for( auto e : art ){
	  cout << e.f.f+1 << " " << e.f.s+1 << " " << e.s << endl;
  }

  return 0;
}

