#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		int t = s.size();
		
		if(t>=2 and s[t-1]=='o' and s[t-2]=='p') cout << "FILIPINO" << endl;
		else if(t>=4 and s[t-1]=='u' and s[t-2]=='s' and s[t-3]=='e' and s[t-4]=='d') cout << "JAPANESE" << endl;
		else if(t>=4 and s[t-1]=='u' and s[t-2]=='s' and s[t-3]=='a' and s[t-4]=='m') cout << "JAPANESE" << endl;
		else if(t>=5 and s[t-1]=='a' and s[t-2]=='d' and s[t-3]=='i' and s[t-4]=='n' and s[t-5]=='m') cout << "KOREAN" << endl;
	}
		


	exit(0);
}
