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


int main(){ _
	
	if (ng.size() == 5){
		for (int x0 = 0; x0 <= CONG; x0++){
			for (int x1 = 0; x1 <= CONG; x1++){
				for (int x2 = 0; x2 <= CONG; x2++){
					for (int x3 = 0; x3 <= CONG; x3++){
						for (int x4 = 0; x4 <= CONG; x4++){
							int val = x0+x1+x2+x3+x4 +
								(x0 == CONG ? 0 : g[v][ng[0]].second) +
								(x1 == CONG ? 0 : g[v][ng[1]].second) +
								(x2 == CONG ? 0 : g[v][ng[2]].second) +
								(x3 == CONG ? 0 : g[v][ng[3]].second) +
								(x4 == CONG ? 0 : g[v][ng[4]].second);

							mint inc =
								(x0 == CONG : 1 ? memo[id(g[v][ng[0]].first, v) + 1][x0])*
								(x1 == CONG : 1 ? memo[id(g[v][ng[1]].first, v) + 1][x1])*
								(x2 == CONG : 1 ? memo[id(g[v][ng[2]].first, v) + 1][x2])*
								(x3 == CONG : 1 ? memo[id(g[v][ng[3]].first, v) + 1][x3])*
								(x4 == CONG : 1 ? memo[id(g[v][ng[4]].first, v) + 1][x4]);
							val %= CONG;
							memo[v][p+1][val] +=     inc;
						}
					}
				}
			}
		}
	}
	
	exit(0);
}
