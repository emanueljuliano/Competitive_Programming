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
		string b, a;
		cin >> a >> b;
		multiset <char> sa;
		bool flag = false;
		for(int i=0; i<a.size(); i++){
			sa.insert(a[i]);
		}
		for(int i=0; i<b.size(); i++){
			multiset <char> sb;
			for(int j=i; j<b.size(); j++){
				sb.insert(b[j]);	
				if(sb.size()==sa.size() and sb==sa) flag=true;
			}
		}

		if(flag){
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;

	}	


	exit(0);
}
