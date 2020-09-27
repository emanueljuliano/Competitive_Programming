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

string s;

bool show(int x){
	int at = 1;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='L') at++;
		else at = 1;
		if(at>x) return false;
	}
	return true;
}

int bb(int l, int r){
	if(l==r) return l;
	int m = (l+r)/2;
	if(show(m)) r = m;
	else l = m+1;
	return bb(l, r);
}

int main(){ _
	int t; cin >> t;	
	while(t--){
		cin >> s;
		cout << bb(1, s.size()+1) << endl;
	}
	
	
	exit(0);
}
