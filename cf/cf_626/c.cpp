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
	int ans = 0;
	int n; cin >> n;
	int at = 0;
	string s; cin >> s;
	if(n%2) return cout << -1 << endl, 0;
	int it = 0;
	for(int i=0;i <n; i++){
		if(s[i]==')') at++;
		else at--;
		if(at==0){
			if(!(i-it==1 and s[i]==')')){
				ans += i-it;
				if(s[i]=='(' and s[it]==')') ans++;
			}
			it = i+1;	
		}
	}
	if(at!=0) return cout << -1 << endl, 0;
	cout << ans << endl;
	
	
	
	exit(0);
}
