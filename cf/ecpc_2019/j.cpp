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

int main(){ 
	freopen("abc.in", "r", stdin); _		
	int n; cin >> n;
	string s, s2; cin >> s;
	int a=0, b=0, c=0;
	for(auto ch : s){
		if(ch=='a') a++, s2+=ch;
		if(ch=='b') b++;
		if(ch=='c') c++, s2+=ch;
	}

	if(a==0 or c==0) return cout << 0 << endl, 0;
	if(!b) return cout << -1 << endl, 0;

	int bi = 0;
	for(int i=0;i <s.size(); i++) if(s[i]=='b') bi=i;
	
	int ans = INF;
	int cc = 0;
	for(int i=0;i <a; i++) if(s2[i]!='a') cc++;
	ans= min(ans, cc+(bi!=a));
	int aa = 0;
	for(int i=0;i <c; i++) if(s2[i]!='c') aa++;
	ans= min(ans, aa+(bi!=c));
	cout << ans << endl;



	
	exit(0);
}
