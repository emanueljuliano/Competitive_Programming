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


int main(){ //_
	int t; cin >> t;
	while(t--){
		ll a, b, p; cin >> a >> b >> p;
		string s; cin >> s;
		vector<int>A, B;
		A.pb(0); B.pb(0);
		ll at = 1;
		char c = s[0];
		vector<int> v, w;
		for(int i=1; i<s.size(); i++){
			if(s[i]!=c){
				if(c=='A')
					A.pb(at), v.pb(a), w.pb(at);
				else
					B.pb(at), v.pb(b), w.pb(at);
				at = 0;
			
				c = s[i];
			}
			at++;
		}
		if(c=='A')
			A.pb(at), v.pb(a);
		else
			B.pb(at), v.pb(b);
		w.pb(at);
		
		/*int anda = 0;
		int ita=0, itb=0;
		for(int i=0; i<A.size(); i++)
			anda += A[i];
		for(int i=0; i<B.size(); i++)
			anda += B[i];
		
		at = 0;
		while(true){
		//	cout << anda << endl;
			if(ita< A.size() and (A[ita]*b > B[itb]*a or p-at<b) and p-at>=a){
				anda -= A[ita];
				at+=a;
				ita++;
			}
			else if(itb < B.size() and (A[ita]*b <= B[itb]*a or p-at<a) and p-at>=b){
				anda -= B[itb];
				at += b;
				itb++;
			}
			else break;
		}
		cout << anda << endl;
		*/
		bool flag = true;
		int anda = 1;
		int aux = p;
		if(s.size()>1 and s[s.size()-1] != s[s.size()-2]){
			v.pop_back();
			w.pop_back();
		}
		
		for(int i=v.size()-1; i>=0; i--){
			if(v[i]<=p and flag) p-=v[i];
			else {flag = false; anda+=w[i];}
		}
		if(v.size()==1){
			if(v[0]<=aux) anda = 1;
			else anda = s.size();
		}
		anda = min((int)anda, (int)s.size());
		cout << anda << endl;
	}
	
	
	
	exit(0);
}
