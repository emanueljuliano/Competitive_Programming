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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n, m, mini, maxi;
	cin >> n >> m >> mini >> maxi;
	vector<int> v(m);
	for(auto &i:v) cin >> i;
	sort(v.begin(), v.end());
	if(v[0]<mini or v.back()>maxi) return cout << "Incorrect" << endl, 0;
	if(v[0]!=mini and v.back()!=maxi and n==m+1) return cout << "Incorrect" << endl, 0;
	cout << "Correct" << endl;
	
	
	
	exit(0);
}
