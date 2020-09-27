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
	int k; cin>> k;
	vector<int> v(12);
	for(auto &i : v) cin >> i;
	sort(v.begin(), v.end(), greater<>());
	int at = 0;
	int x = 0;
	for(int i=0; i<12; i++){
		if(at>=k) break;
		x++;
		at += v[i];
	}
	if(at<k) cout << -1 << endl;
	else cout << x << endl;
	
	
	
	exit(0);
}
