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
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int ab1 = 0, ab2=0;
		int ans =0;
		for(auto c : s){
			if(c=='(') ab1++;
			if(c=='[') ab2++;
			if(c==')' and ab1) ab1--, ans++;
			if(c==']' and ab2) ab2--, ans++;
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
