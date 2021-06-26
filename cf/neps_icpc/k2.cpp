#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for (auto& i : v) cin >> i;
    int qt_bom = 0;
    vector<int> bom(n);
    multiset<int> R = {INF};
    vector<int> rr(n, -1);
    pair<int, int> ans = {0, m-1};
    for (int i = m-1; i >= 0; i--) {
        for (int j = 1; j < n; j++) {
            if (v[j-1][i] < v[j][i]) { // bom
                R.erase(R.find(rr[j]));
                rr[j] = i;
                R.insert(rr[j]);
                if (!bom[j]) bom[i] = 1, qt_bom++;
            } else if (v[j-1][i] > v[j][i]) { // ruim
                if (bom[j]) bom[i] = 0, qt_bom--;
            }
        }
        int r = *R.rbegin();
        if (qt_bom == n-1 and r-i < ans.second - ans.first) ans = {i, r};
    }
    cout << ans.first+1 << " " << ans.second+1 << endl;
    exit(0);
}
