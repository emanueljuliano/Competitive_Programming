#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _

	int n;
	cin >> n;
	for(int k=0; k<n; k++){
		string a, b;
		cin >> a >> b;
		string c=a;
		sort(c.begin(), c.end());

		if (a!=c){
			char mini;
			int pos=-1;
			for(int i=0; i<a.size(); i++){
				if(a[i]!=c[i]){mini = c[i]; pos=i; break;}
			}
			for(int i=a.size()-1; i>0; i--){
				if(a[i]==mini) {swap(a[pos], a[i]); break;} 
			}
		}

		if(a==b){ cout << "---" << endl; continue;}
		for(int i=0; i<a.size(); i++){
			if(i==b.size()) {cout << "---" << endl; break;}
			if(a[i]<b[i]) {cout << a << endl; break;}
			if(a[i]>b[i]){ cout << "---" << endl; break;}
			if(i==a.size()-1) {cout << a << endl; break;}
		} 
	}
	
	exit(0);
}
