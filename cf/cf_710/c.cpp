#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;

		int ans = a.size()+b.size();
		for(int i=0;i <a.size(); i++)
			for(int j=0; j<a.size(); j++)
				for(int k=0; k<b.size(); k++)
					if(a.substr(i, j-i+1) == b.substr(k, j-i+1))
						ans = min(ans, int(a.size()+b.size())-2*(j-i+1));
		cout << ans << endl;
	}
		
	
	exit(0);
}
