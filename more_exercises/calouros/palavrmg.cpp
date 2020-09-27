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
		string a; cin >> a;
		bool sort = true;
		for(int i=1;i <a.size(); i++){
			int x = a[i-1]-'a', y = a[i]-'a';
			if(x<0) x += 'a' - 'A';
			if(y<0) y += 'a' - 'A';
			if(x>=y) sort = false;
		}
		if(sort) cout << a << ": O" << endl;
		else cout << a << ": N" << endl;
	
	}
	
	
	
	exit(0);
}
