#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ss second
#define ff first
 
typedef pair<int, int> pii;
typedef long long ll;
 
int main(){ _
 
	int n;
	cin >> n;
	set <int> ent;
	set <int> sai;
	int a;
	vector<int> ans;
	int c=0;
	for(int i=0; i<n; i++){
		cin >> a;
		if(a>0){
			if(!ent.count(a))	
				ent.insert(a);
			else if(ent.count(a)){
				if(!sai.count(a)){
					cout << -1 << endl;
					exit(0);
				}
 
				else{
					if(sai==ent){
						sai.clear();
						ent.clear();
						ent.insert(a);
						ans.push_back(c);
						c=0;
					}
					else{
						cout << -1 << endl;
						exit(0);
					}
				}
			}
 
 
		}
		else{
			if(ent.count(-a) and !sai.count(-a))
				sai.insert(-a);
			else if(ent.count(-a) and sai.count(-a)){
				cout << -1 << endl;
				exit(0);
			}
			else if(!ent.count(-a)){
				cout << -1 << endl;
				exit(0);
			}
		}
		c++;
	}
 
		ans.push_back(c);
		cout << ans.size() << endl;
		for(int i=0; i<ans.size(); i++){
			cout << ans[i] << " ";
		}
		cout << endl;
 
	exit(0);
}
