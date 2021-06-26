#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	vector<int> v(n);
	
	for(auto &i : v) cin >> i;
	int l = 0;
	while(l<n-1 and v[l]<=v[l+1]) l++;
	int r = n-1;
	while(r>0 and v[r]>=v[r-1]) r--;
	if(r>l){
		while(l>0 and v[l]==v[l-1]) l--;
		while(r<n-1 and v[r]==v[r+1]) r++;
		
		bool show = true;
		for(int j=l; j<r; j++) if(v[j]<v[j+1]) show = false;
		if(l>0 and v[r]<v[l-1]) show = false;
		if(r<n-1 and v[l]>v[r+1]) show = false;

		if(show) cout << l+1 << " "<< r+1 << endl;
		else cout << "impossible" << endl;
	}	
	else{
		cout << 1 << " " << 1 << endl;
	}

	
	
	exit(0);
}
