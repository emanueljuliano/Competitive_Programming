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
	string s; cin >> s;
	int n = s.size();
	int x=0, y=0;
	int at = 1<<n;
	for(auto c : s){
		int a = c-'0';
		at/=2;
		if(a%2) x+=at;
		if(a>1) y+=at;
	}
	
	cout << n << " " << x << " " << y << endl;
	
	
	exit(0);
}
