#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);


int main(){ _
	int n, k, a;
	cin >> n >> k;
	vector <int> v;
	set <int> s;
	for(int i=0; i<k; i++) v.push_back(-1);
	for(int i=0; i<n; i++){
		cin >> a;
		bool flag = true;
		if(!s.count(a)){
			v.push_back(a);
			if(s.size()>=k){
				s.erase(v[v.size()-1-k]);
			}
			s.insert(a);
		}
	}
	int count = 0;
	for(int i=v.size()-1; i>v.size()-k-1; i--){
		if(v[i]!=-1) count++;
	}
	cout << count << endl;
	for(int i=v.size()-1; i>v.size()-k-1; i--){
		if(v[i]!=-1) cout << v[i] << " ";
	}
	cout << endl;	
}
