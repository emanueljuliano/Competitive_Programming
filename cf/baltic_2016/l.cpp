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
	int n; cin >> n;
	int sad=0, happy=0;
	string s; cin >> s;
	for(int i=0;i <n-1; i++){
		if(s[i]==':' and s[i+1]==')') happy++;
		if(s[i]==':' and s[i+1]=='(') sad++;
		if(s[i]=='(' and s[i+1]==':') happy++;
		if(s[i]==')' and s[i+1]==':') sad++;
	}
	if(happy==sad) cout << "BORED" << endl;
	else if(happy>sad) cout << "HAPPY" << endl;
	else cout << "SAD" << endl;
	
	
	exit(0);
}
