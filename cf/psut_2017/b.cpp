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
		
	int hp = 0;
	string s; cin >> s;
	s+='$';
	int n = s.size();
	vector<int> happy(n+1);
	for(int i=n-1;i+1; i--){
		if(s[i]==':' and s[i+1]==')') hp++;
		happy[i] = hp;
	}

	int ans = happy[0], sad = 0;
	for(int i=1;i <n; i++){
		if(s[i-1]=='(' and s[i]==':') sad++, ans=max(ans, sad+happy[i+1]);
		if(s[0]==':' and s[i+1]==')') ans = max(ans, sad+1+happy[i+1]);
	}
	cout << ans << endl;

	
	
	exit(0);
}
