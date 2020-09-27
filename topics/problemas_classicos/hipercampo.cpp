#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair <int, int> pii;

int n, A, B;
vector < pii > v;

bool posso(pii a, pii b){
	return (A*a.y + a.x *b.y - b.x *a.y - b.y *A > 0 and
			B*a.y + a.x * b.y - b.x *a.y - b.y *B < 0);
}

bool ordena(pii a, pii b){
	if(a.y==b.y) return a.x > b.x;
	return a.y<b.y;
}

int pd[110];
int rec(int pos){
	if(pd[pos]!=-1) return pd[pos];
	pii p = v[pos];
	if(pos == n-1) return 0;
	int maxi = 0;
	for(int i=pos+1; i<n; i++){
		if(!posso(p, v[i])) continue;
		maxi = max(maxi, 1+rec(i));
	}
	return pd[pos] = maxi;
	
}


int main(){
	memset(pd, -1, sizeof(pd));
	int a,  b;
	cin >> n >>  A >> B;

	for(int i=0; i<n; i++){
		cin >> a >> b;
		v.push_back({a, b});
	}
	int maxi = 1;
	sort(v.begin(), v.end(), ordena);
	for(int i=0; i<n; i++){
		maxi = max(maxi, 1+rec(i));
	}
	
	cout << maxi << endl;






}
