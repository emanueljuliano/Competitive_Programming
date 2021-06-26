#include <bits/stdc++.h>
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define Unique(v) sort(all(v));v.erase(unique(all(v)),v.end());
#define sz(v) ((int)v.size())
#define int long long  
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
//#define left oooooopss
#define db(x) cerr << #x <<" == "<<x << endl;
#define db2(x,y) cerr<<#x <<" == "<<x<<", "<<#y<<" == "<<y<<endl;
#define db3(x,y,z) cerr << #x<<" == "<<x<<", "<<#y<<" == "<<y<<", "<<#z<<" == "<<z<<endl;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
//inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll b,ll e,ll m){
  b%=m;
  ll ans = 1;
  for (; e; b = b * b % m, e /= 2)
      if (e & 1) ans = ans * b % m;
  return ans;
}

const int mod = 998244353;
int modinv(int x){
  return exp(x , mod - 2 , mod);
}
int solveLinear(vector<vi>& A, vi& b, vi& x) {
  rep(i,0,sz(A)){
    rep(j,0,sz(A[i])){
      A[i][j] = ((A[i][j])%mod + mod)%mod;
    }
  }
  rep(i,0,sz(b)){
    b[i] = (b[i]%mod + mod)%mod;
  }
  int n = sz(A), m = sz(x), rank = 0, br, bc;
  vi col(m); 
  for(int i = 0 ; i < sz(col) ; i++) col[i] = i;
  rep(i,0,n) {
    int v, bv = -1;
    rep(r,i,n) rep(c,i,m)
      if ((v = A[r][c])) {
        br = r, bc = c, bv = v;
        goto found;
      }
    rep(j,i,n) if (b[j]) return -1;
    break;
found:
    swap(A[i], A[br]);
    swap(b[i], b[br]);
    swap(col[i], col[bc]);
    rep(j,0,n) swap(A[j][i], A[j][bc]);
    bv = modinv(A[i][i]);
    rep(j,i+1,n) {
      int fac = (A[j][i] * bv) % mod;
      b[j] = ((b[j] - fac * b[i]) % mod + mod)%mod;
      rep(k,i+1,m) A[j][k] = ((A[j][k] - fac*A[i][k]) % mod + mod)%mod;
    }
    rank++;
  }

  x.assign(m, 0);
  for (int i = rank; i--;) {
    b[i] = ((b[i] * modinv(A[i][i]) % mod) + mod) % mod;
    x[col[i]] = b[i];
    rep(j,0,i)
      b[j] = ((b[j] - A[j][i] * b[i])%mod + mod)%mod;
  }
  return rank;
}

const int N = 100100,MX = 512;
int cnt[MX+1];
int deg[N];
vi g[N],rg[N];
int mex[N];

int32_t main(){
  fastio;
  int n,m;
  cin >> n >> m;
  rep(i,0,m){
    int a,b;
    cin>>a>>b;
    g[a].pb(b);
    rg[b].pb(a);
    deg[a]++;
  }
  queue<int> q;
  rep(i,1,n+1){
    if(deg[i]==0)q.push(i);
  }
  while(!q.empty()){
    int c = q.front();
    q.pop();
    set<int> S;
    for(auto to : g[c]){
      S.insert(mex[to]);
    }
    for(int i=0;;i++){
      if(!S.count(i)){
        mex[c] = i;
        break;
      }
    }
    for(auto to : rg[c]){
      if(--deg[to] == 0)q.push(to);
    }
    cnt[mex[c]]++;
  }
  const int mx = 6;
  vector<vi> A(mx,vi(mx,0));
  vi x(mx);
  vi b(mx);
  int P = modinv(n+1);
  rep(i,0,mx){

    rep(a,0,mx)A[i][a]=0;
    A[i][i] = +1;

    if(i!=0)
      b[i] = P;
    else b[i]=0;
    rep(a,0,mx){
      A[i][a] = (A[i][a] + mod - 1ll*P%mod*(ll)cnt[a^i]%mod)%mod;
    }

  }
	for(auto u : A){
		for(auto uu : u) cout << uu << " ";
		cout << endl;
	}
  solveLinear(A,b,x);
  cout << x[0] << endl;

  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}
