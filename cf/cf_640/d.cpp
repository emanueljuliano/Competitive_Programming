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
		vector<int> v;
		for(int i=0;i <n; i++){
			int a; cin >> a; v.pb(a);
		}
		int it1 = 0, it2=n-1;
		int s1 = 0, s2=0;
		bool vez = true;
		int r = 0;
		int s = 0;
		while(it1<=it2){
			r++;
			int at = 0;
			if(vez){
				while(at <=s){
					at += v[it1];
					it1++;
					if(it1>it2) break;
				}
				s1+=at;
				vez = false;
			}
			else{
				while(at<=s){
					at += v[it2];
					it2--;
					if(it1>it2) break;
				}
				s2+=at;
				vez = true;
			}
			s = at;
		}
		cout << r << " " << s1 << " " << s2 << endl; 
	}
	
	
	
	exit(0);
}
