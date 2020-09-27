#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
 
typedef long long ll;
 
int ans1=0, ans2=0;
int n, m;
vector<vector<int>> v(300100);
 
vector<int> submask(int a){
	vector<int> ret;
	for (int i=a; i>0; i=(i-1) & a){
		ret.pb(i);
	}
	ret.pb(0);
	return ret;
}
 
 
int pode(int x){
	int mask[256];
	for(int i=0; i<256; i++)
		mask[i] = -1;
 
	for(int i=0; i<n; i++){
		int ma = 0;
		for(int j=0; j<m; j++){
			if(v[i][j]>= x)
				ma |= (1<<j);	
		}
		if (mask[ma] != -1) continue;
		for(int num : submask(ma)){
			mask[num] = i+1;
		}
	}
	int aux = 1<<m;
	aux--;
 
	for(int i=0; i<256; i++){
		if(mask[i]!=-1 and mask[(~i) & aux] != -1){
			ans1 = mask[i];
			ans2 = mask[(~i)&aux];
//			cout << x << " " <<ans1 << " " << ans2 << endl;
			return 1;
		}
	}
	return 0;
}
 
int bb(int l, int r){
	if(l==r) return l;
	int mid = (l+r)/2;
	
	if(pode(mid)){
		return bb(mid+1, r);
	}
	else{
		return bb(l, mid);
	}
}
 
int main(){ //_
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int a; cin >> a;
			v[i].pb(a);
		}
	}
	bb(0, 1e9+1);
	cout << ans1 << " " << ans2 << endl;
		
	exit(0);
}
