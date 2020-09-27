#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n, k;
	cin >> n >> k;
	string s[1510];
	int ans=0;
	set <string> se;
	for(int i=0; i<n; i++){
		cin >> s[i];
		se.insert(s[i]);
	}
	//dif
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			string aux = "";
			for(int ii=0; ii<k; ii++){
				if(s[i][ii]==s[j][ii])
					aux.pb(s[i][ii]);
				else{
					if(s[i][ii]!='S' and s[j][ii]!='S')
						aux.pb('S');
					if(s[i][ii]!='E' and s[j][ii]!='E')
						aux.pb('E');
					if(s[i][ii]!='T' and s[j][ii]!='T')
						aux.pb('T');
				}
			}
			if(se.count(aux)) ans++;
		}
	}
	cout << ans/3 << endl;
	//igu

	exit(0);
}
