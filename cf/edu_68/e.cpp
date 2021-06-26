#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define read(x) for(auto& qw : (x)) cin >> qw;
#define print(x) for(auto& qw : (x)) cout << qw << " "; cout << endl;
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MAX = 2*5000 + 10;
 
struct bit {
    int n;
    vector<ll> tree;
    bit(int n_) : n(n_) { tree.resize(n+1); }
    void add_(ll x, int p) {
        p++;
        while(p <= n) tree[p] += x, p += p & -p;
    }
    ll pref_(int p) {
        ll ret = 0; p++;
        while(p > 0) ret += tree[p], p -= p & -p;
        return ret;
    }
    void add(ll x, int l) {
        add_(x, l);
    }
    ll pref(int p) { return pref_(p); }
    ll sum(int l, int r) { return pref(r) - pref(l-1); }
};
 
void test_case(){
 
    int N;
    cin >> N;
 
    vector<pair<ii,ii>> V(N);
 
    vector<pair<int,ii>> E; // pos,tipo,id
 
    for(int i = 0; i < N; i++){
        // 0 : linha comeca
        // 1 : vertical comeca
        // 2 : linha termina
 
        cin >> V[i].f.f >> V[i].f.s >> V[i].s.f >> V[i].s.s;
 
        V[i].f.f += 5000;
        V[i].f.s += 5000;
        V[i].s.f += 5000;
        V[i].s.s += 5000;
 
        if(V[i].f.f == V[i].s.f){
 
            if(V[i].f.s > V[i].s.s)
                swap(V[i].f.s, V[i].s.s);
 
            E.pb({V[i].f.f, {1, i}});
        }
        else{
 
            if(V[i].f.f > V[i].s.f)
                swap(V[i].f.f, V[i].s.f);
 
            E.pb({V[i].f.f, {0, i}});
            E.pb({V[i].s.f, {2, i}});
        }
 
    }
 
    sort(all(E));
    ll ans = 0;
 
    vector<bit> BITS(MAX, MAX);
 
    vector<int> done;
 
    for(auto it : E){
        int pos = it.f;
        int tipo = it.s.f;
        int id = it.s.s;
 
        if(tipo == 1){
            for(int ver : done){
                
                int left = max(V[ver].f.s, V[id].f.s);
                int right = min(V[ver].s.s, V[id].s.s);
 
                if(left > right)
                    continue;
 
                ll intersect = BITS[V[ver].f.f].sum(left,right);
                ans += intersect * (intersect - 1) / 2;
            }
            
            done.pb(id);
        }
        else{
            int left = V[id].f.f;
            int right = V[id].s.f;
 
            for(int i = left; i <= right; i++){
                BITS[i].add((tipo ? -1 : 1), V[id].f.s);
            }
        }
 
    }
 
    cout << ans << endl;
 
}
 
int main(){ _
 
    int tt = 1;
 
    while(tt--){
        test_case();
    }
 
    return 0;
}
