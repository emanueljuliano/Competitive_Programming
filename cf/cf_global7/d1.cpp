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

bool palyn(string s){
	for(int i=0; i<s.size(); i++){
		if(s[i] != s[s.size()-1-i]) return false;
	}
	return true;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		string pref, suf;
		for(int i=0; i<s.size()/2; i++){
			if(s[i]==s[s.size()-i-1]){
				pref.pb(s[i]);
				if(i!=s.size()-1-i)
					suf.pb(s[s.size()-1-i]);
			}
			else break;
		}
		int q = pref.size();
		string aux;
		string paux;
		for(int i=q; i<s.size()-q; i++){
			aux.pb(s[i]);
			if(palyn(aux)) paux=aux;
		}
		aux = paux;
		string aux2;
		string saux;
		for(int i=s.size()-q-1; i>=q; i--){
			aux2.pb(s[i]);
			if(palyn(aux2)) saux=aux2;
		}
		aux2 = saux;
		if(aux.size()>aux2.size()){
			cout << pref;
			cout << aux;
			reverse(suf.begin(), suf.end());
			cout << suf;
			cout << endl;
		}
		else{
			cout << pref;
			reverse(aux2.begin(), aux2.end());
			cout << aux2;
			reverse(suf.begin(), suf.end());
			cout << suf;
			cout << endl;
		}
	}
	
	
	
	exit(0);
}
