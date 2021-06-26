#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	
	ll sum=0, sum2=0;
	int cnt=0;
	vector<int> v;

	for(int i=0;i <n; i++){
		int a, b; cin >> a >> b;
		sum2 += a;
		if(b==0) cnt++;
		else v.push_back(a-b+1), sum += a;
	}
	
	sort(v.begin(), v.end());

	if(cnt==1) cout << v.back()+1 << " " << sum2 << endl;
	else if(cnt != 0 or v.size()==1) cout << v.back() << " " << sum << endl;
	else cout << min(v[v.size()-2]+1, v.back()) << " " << sum << endl;
	
	
	exit(0);
}
