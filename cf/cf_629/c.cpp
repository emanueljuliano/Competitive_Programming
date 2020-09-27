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
		int n; cin >> n;
		string a, b;
		string s; cin >> s;
		int ma=0;
		for(int i=0; i<n; i++){
			if(s[i]=='2'){
				if(ma==0){
					a.pb('1');
					b.pb('1');
				}
				else if(ma==1){
					a.pb('0');
					b.pb('2');
				}
			}
			else if(s[i]=='1'){
				if(ma==0){
					a.pb('1');
					b.pb('0');
					ma = 1;
				}
				else if(ma==1){
					b.pb('1');
					a.pb('0');
				}
			}
			else a.pb('0'), b.pb('0');
		}
		cout << a << endl << b << endl;
	}
	
	
	
	exit(0);
}
