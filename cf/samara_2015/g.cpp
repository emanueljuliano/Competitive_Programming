#include<bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

int main(){ _
	int n; cin >> n;
	vector<int> v;
	vector<pair<int, int>> ans;
	for(int i=0;i <2*n; i++){
		string s; int a; cin >> s >> a;

		if(s[0]=='i'){
			if(v.size()) ans.push_back({v.back(), a});
			v.push_back(a);
		}
		else v.pop_back();
	}

	for(auto [a, b] : ans) cout << a << " " << b << endl;

}
