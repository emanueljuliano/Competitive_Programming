#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long ll;

int grun[12] = {0, 1, 0, 1, 2, 0, 2, 0, 1, 0, 1, 0};

int g(int x){
	if(x<12) 
		return grun[x];
	if(x%2==1)
		return 0;
	if(g(x/2)==1)
		return 2;
	return 1;
}

int main(){
	int n, k;
	int ans = 0;
	cin >> n >> k;
	vector<int> v;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		v.pb(a);
	}
	if(k%2==0){	
		for(int i=0; i<n; i++){
			if(v[i]==1)
				ans ^= 1;
			if(v[i]==2)
				ans^=2;
			else if (v[i]%2==0)
				ans ^= 1;
		}
		if(ans == 0)
			cout << "Nicky" << endl;
		else
			cout << "Kevin" << endl;
		exit(0);
	}

	else{
		for(int i=0; i<n; i++){
			ans ^= g(v[i]);
		}
		if(ans == 0)
			cout << "Nicky" << endl;
		else
			cout << "Kevin" << endl;
		exit(0);
	
	}
}
