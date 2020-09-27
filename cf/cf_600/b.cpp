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
	if(n%2!=0){
		cout << -1 << endl;
		exit(0);	
	}
	set <int> ent;
	set <int> sai;
	int a;
	vector<int> ans;
	int c=0;
	int dif = 0;
	for(int i=0; i<n; i++){
		cin >> a;
		if(a>0){
			if(!ent.count(a)){	
				ent.insert(a);
				dif +=1;
			}
			else{
				if(!sai.count(a)){
					cout << -1 << endl;
					exit(0);
				}

				else{
					if(sai==ent){
						cout << -1 << endl;
						exit(0);
					}
				}
			}


		}
		else{
			if(ent.count(-a)){
				if(sai.count(-a)){
					cout << -1 << endl;
					exit(0);
				}
				else{
					sai.insert(-a);
					dif-=1;
				}
			}
			else{
				cout << -1 << endl;
				exit(0);
			}
		}
		if(dif==0){
			sai.clear();
			ent.clear();
			ans.push_back(c+1);
			c=-1;
		}
		c++;
	}
	if(ent!=sai){
		cout << -1 << endl;
		exit(0);
	}

	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;

	exit(0);
}
