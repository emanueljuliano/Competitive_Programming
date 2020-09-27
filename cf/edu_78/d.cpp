#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n;	
	cin >> n;
	vector <int> v(1e6+100, 0);
	for(int i=0; i<1e6+100; i++)v[i]=0;
	int maxi=0;
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		maxi = max(maxi, b);
		v[a]+=1;
		v[b]-=1;
	}
	for(int i=1; i<=maxi; i++) {cout << v[i] << " ";v[i]+= v[i-1]; } cout << endl;
	bool flag1 = false;
	int tot=0;
	for(int i=0; i<maxi; i++){
		cout << i << " ";
		if(v[i]>2) flag1 = true;
		if(v[i+1]==2 and v[i]==1){cout << i << " "; tot++;}
	}

	if(flag1) cout << "NO" << endl;
	else if(tot<n) cout <<"NO" << endl;
	else cout << "YES" << endl;
	exit(0);
}
