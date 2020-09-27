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
	string s;
	for(int i=0;i <n; i++){
		string a; cin >> a;
		s+=a;
		if(i!=n-1) s+=" ";
	}
	int k; cin >> k;
	bool caps = false;
	string s2="";
	while(k--){
		string a; cin >> a;
		if(a=="CapsLock") caps = !caps;
		else if(a=="Backspace"){ if(!s2.empty()) s2.pop_back();}
		else if(a=="Space") s2.pb(' ');
		else{
			if(caps) s2.pb(a[0]-'a'+'A');
			else s2.pb(a[0]);
		}
//		cout << k << " " << a <<  " " << s2 << endl;
	}
//	cout << s << endl;
//	cout << s2 << endl;
	if(s2==s) cout << "Correct" << endl;
	else cout << "Incorrect" << endl;
	
	
	exit(0);
}
