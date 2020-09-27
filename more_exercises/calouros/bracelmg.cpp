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
	int t; cin >> t;
	while(t--){
		string a, b; cin >> b >> a;
		bool flag = false;
		for(int i=0;i <a.size(); i++) if(a[i]==b[0]){
			bool show = true;
			for(int j=0; j<b.size(); j++)
				if(b[j]!=a[(j+i)%a.size()]) show = false;
			flag |= show;
		}
		reverse(a.begin(), a.end());
		for(int i=0;i <a.size(); i++) if(a[i]==b[0]){
			bool show = true;
			for(int j=0; j<b.size(); j++)
				if(b[j]!=a[(j+i)%a.size()]) show = false;
			flag |= show;
		}

		if(flag) cout << "S" << endl;
		else cout << "N" << endl;
	}
	
	
	
	exit(0);
}
