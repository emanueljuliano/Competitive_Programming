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

int A[MAX];
int S[MAX][8];
vector<ii> v;

int main(){ _
	int n, p, k; cin >> n >> p >> k;
	for(int i=0;i <n; i++){
		cin >> A[i];
		v.pb({A[i], i});
	}
	for(int i=0;i <n; i++){
		for(int j=0; j<p; j++){
			cin >> S[i][j];
		}
	}
	sort(v.begin(), v.end(), greater<>());
	
	build();
	
	
	
	exit(0);
}
