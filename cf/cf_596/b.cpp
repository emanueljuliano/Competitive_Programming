#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"


int main(){ _
	int t, n , k, d;
	int tam[1001000];
	memset(tam, 0, sizeof(tam));
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> n >> k >> d;
		vector <int> v;
		int aux;
		int mini = 0;
		for(int j=0;j<n; j++){
			cin >> aux;
			
			if(j<d){
				if(tam[aux]==0)
					mini++;
				tam[aux]++;
			}
			v.push_back(aux);
		}
		int at=mini;
		for(int j=d; j<n; j++){
			tam[v[j-d]]--;
			if(tam[v[j-d]]==0)
				at--;	
			if(tam[v[j]]==0)
				at++;
			tam[v[j]]++;
			mini = min(mini, at);
			
			//cout <<"s "<< s.size() << endl;	
		}
		for(int  j=n-d; j<n; j++){
			tam[v[j]] = 0;
		}
		cout << mini << endl;
	}
	

	exit(0);
}
