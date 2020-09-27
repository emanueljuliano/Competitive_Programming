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
bool solve(char r, char g, char b){
	int n = s.size();
	int R = -1, G=-1, B=-1;	
//	cout << r << " " << g << " " << b << endl;
	for(int i=0;i <n; i++){
		if(s[i] ==r) R = i;
		else if(s[i]==g) G = i;
		else if(s[i] == b) B = i;
	}
	if(R==-1 or G==-1 or B==-1) return true;
	
	string t;
	for(int i=0;i <n; i++){
		if(i<=R and s[i]!=r) t.pb(s[i]);
		if(i>R and s[i]!=g) t.pb(s[i]);
	}
	G = -1;
	for(int i=0;i <t.size(); i++){
		if(t[i]==g) G = i;
	}
	for(int i=0;i <t.size(); i++){
		if(t[i]==b and i<G) return false;
	}
	return true;

}


int main(){ _
	cin >> s;
	bool ans = false;
	ans |= solve('R', 'G', 'B');
	ans |= solve('R', 'B', 'G');
	ans |= solve('G', 'R', 'B');
	ans |= solve('G', 'B', 'R');
	ans |= solve('B', 'R', 'G');
	ans |= solve('B', 'G', 'R');
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;

	exit(0);
}
