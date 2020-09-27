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
	int cs = 0;
	while(t--){
		cs++;
		int n; cin >> n;
		
		string ini, end, mid;
		bool flag = true;
		string poans;
		vector<string> ent;
		for(int i=0;i <n; i++){
			string s; cin >> s;
			ent.pb(s);
			int asc = 0;
			for(int j=0;j <s.size(); j++) if(s[j]=='*') asc++;
			if(asc==0){
				if(poans.empty()) poans = s;
				else if(poans != s) flag = false;
			}
			if(s[0]!='*'){
				bool show = false;
				for(int j=0;j <ini.size(); j++){
					if(s[j]=='*') {show = true; break;}
					if(ini[j]!=s[j]) flag = false;
				}
				if(!show)
				for(int j=ini.size(); j<s.size(); j++){
					if(s[j]=='*') break;
					ini.pb(s[j]);
				}
	
			}
			if(s.back()!='*'){
				bool show = false;
				reverse(s.begin(), s.end());
				for(int j=0;j <end.size(); j++){
					if(s[j]=='*') {show = true; break;}
					if(end[j]!=s[j]) flag = false;
				}
				if(!show)
				for(int j=end.size(); j<s.size(); j++){
					if(s[j]=='*') break;
					end.pb(s[j]);
				}
			}
			
			if(asc>=2){
				int it1= 0, it2=0;
				for(int j=0;j <s.size(); j++) if(s[j]=='*'){it1 = j; break;}
				for(int j=s.size()-1;j >=0; j--) if(s[j]=='*'){it2 = j; break;}

				for(int j=it1; j<=it2; j++){
					if(s[j]!='*') mid.pb(s[j]);
				}
			}
		}
		reverse(end.begin(), end.end());
		poans = ini+mid+end;
		if(!poans.empty()){
			vector<string> v;
			for(auto s : ent){
				int acs=0;
				
				v.resize(0);
				string aux;
				for(int i=0;i <s.size(); i++){
					while(i<s.size() and s[i]!='*') aux.pb(s[i]), i++;
					if(!aux.empty()) v.pb(aux), aux.resize(0);
				}
				int at = 0;
				int count = 0;
				bool found = false;
				for (auto ss : v){
				//	cout << ss << " " << at << endl;
					count ++;
					int at1 = at;
					for(int i=at;i <=poans.size()-ss.size(); i++) if(poans[i]==ss[0]){
						bool fflag = true;
						for(int j=0; j<ss.size(); j++){
							if(poans[i+j]!=ss[j]) fflag = false;
						}	
						if(fflag){
						//	cout << "fflag " << ss << " " << at << endl;
							if(count==v.size()) found = true;
							at = i+ss.size(); break;
						}
					}
					if(at1==at) flag = false;
				}
				if(!found) flag = false;		
			}
			ini = poans;
			mid = "";
			end = "";
		}
		if(!flag){
			cout << "Case #" << cs << ": *" << endl;
		}
		else
			cout << "Case #" << cs << ": " << ini << mid << end << endl;
	
	}
	
	
	
	exit(0);
}

