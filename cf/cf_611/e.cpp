#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	
	int n;
	cin >> n;
	vector <int> v, w;
	set <int> s;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		if(s.count(a)){
			v.pb(a);
		}
		else{
			v.pb(a);
			w.pb(a);
			s.insert(a);
		}
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());

	int mini=0;
	for(int i=0; i<w.size(); i++){
		if(i==w.size()-1) mini++;
		else if(w[i+1]-w[i]>2){
			mini++;
		}
		else{
			mini++;
			++i;
			if(i<w.size()-1 and w[i+1]-w[i-1]<=2) ++i;			
		}
	}
	int maxi = 0;
	map <int, int> ma;
	for(int i=0; i<v.size(); i++){
		if(ma[v[i]-1]==0){
			maxi++;
			ma[v[i]-1]=1;
		}
		else if(ma[v[i]]==0){
			ma[v[i]]=1;
			maxi++;
		}
		else if(ma[v[i]+1]==0){
			maxi++;
			ma[v[i]+1]=1;
		}
	}

	cout << mini << " " << maxi << endl;
	exit(0);
}
