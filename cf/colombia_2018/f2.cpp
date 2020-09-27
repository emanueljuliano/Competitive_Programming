#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 27*100+10;
const int sig = 26;

vector<int> g[MAX];
int match[MAX]; // match[i] = com quem i esta matchzado ou -1
int n, pai[MAX], base[MAX], vis[MAX];
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
    for (int i = 0; i < n; i++) {if(g[i].empty()) continue; if (match[i] == -1)
        for (int j : g[i]) if (match[j] == -1) {
            match[i] = j;
            match[j] = i;
            ans++;
            break;
        }
	}
    for (int i = 0; i < n; i++) {if(g[i].empty()) continue; if (match[i] == -1){
        int j = getpath(i);
        if (j == -1) continue;
        ans++;
        while (j != -1) {
            int p = pai[j], pp = match[p];
            match[p] = j;
            match[j] = p;
            j = pp;
        }
    }}
    return ans;
}

int m = 0;
int main(){ _
	cin >> n;
	vector<int> alp(sig);
	vector<vector<int>> v(n);

	for(int i=0;i <n; i++){
		for(int j=0; j<sig; j++) alp[j]=0;
		int maxi = 0;

		for(int j=0;j <3; j++){
			string s; cin >> s;
			for(auto c : s){
				alp[c-'A']++; maxi = max(maxi, alp[c-'A']), m = max(m, c-'A'+1);
			}
		}

		for(int j=0; j<sig; j++) if(alp[j]==maxi) v[i].pb(j);
	}

	int k; cin >> k; m*=k;
	for(int i=0;i <n; i++) for(auto c : v[i]) for(int j=0; j<k; j++) 
		g[i].pb(n+k*c+j), g[n+k*c+j].pb(i);

	n += m;
	int ans = blossom();
	cout << ans << endl;;

	exit(0);
}
