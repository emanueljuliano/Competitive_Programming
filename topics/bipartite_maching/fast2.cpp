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
const int MAX = 1e5+10;
const int MAX2 = 5e4+10;

// Blossom - matching maximo em grafo geral
//
// O(n^3)
// Se for bipartido, nao precisa da funcao
// 'contract', e roda em O(nm)

vector<int> g[MAX];
int match[MAX]; // match[i] = com quem i esta matchzado ou -1
int n, m, pai[MAX], base[MAX], vis[MAX];
queue<int> q;
 
int getpath(int s) {
    for (int i = 0; i < n; i++) base[i] = i, pai[i] = -1, vis[i] = 0;
    vis[s] = 1; q = queue<int>(); q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int i : g[u]) {
            if (base[i] == base[u] or match[u] == i) continue;
            else if (pai[i] == -1) {
                pai[i] = u;
                if (match[i] == -1) return i;
                i = match[i];
                vis[i] = 1; q.push(i);
            }
        }
    }
    return -1;
}
 
int blossom() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < n; i++) if (match[i] == -1)
        for (int j : g[i]) if (match[j] == -1) {
            match[i] = j;
            match[j] = i;
            ans++;
            break;
        }
    for (int i = 0; i < n; i++) if (match[i] == -1) {
        int j = getpath(i);
        if (j == -1) continue;
        ans++;
        while (j != -1) {
            int p = pai[j], pp = match[p];
            match[p] = j;
            match[j] = p;
            j = pp;
        }
    }
    return ans;
}

int main(){ _
	int p; cin >> n >> m >> p;
	for(int i=0;i <p; i++){
		int a, b; cin >> a >> b; a--; b--;
		g[a].pb(n+b);
		g[n+b].pb(a);
	}
	n += m;
	int ans = blossom();
	cout << ans << endl;


	exit(0);
}
