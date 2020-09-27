#include <bits/stdc++.h>

using namespace std;

#define inf 0x3f3f3f3f
const int MAX = 112345;
int t[4*MAX];
int a[MAX];

void build(int node, int start, int end){
	if(start==end) // folha
		t[node] = a[start];

	else{
		int mid = (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		
		t[node] = min(t[2*node], t[2*node+1]); // mudar
	}
}

void update(int node, int start, int end, int idx, int val){
	if(start==end){ // folha - mudar
		a[idx] = val;
		t[node] = val;
	}
	else{
		int mid = (start+end)/2;
		if(start<= idx and idx<=mid)
			update(2*node, start, mid, idx, val);
		else 
			update(2*node+1, mid+1, end, idx, val);

		t[node] = min(t[2*node], t[2*node+1]); // mudar
	}
}

int query(int node, int start, int end, int l, int r){
	if(r<start or end <l) // fora
		return inf; // mudar

	if(l <= start and end <= r) // dentro
		return t[node];
	
	// parcial
	int mid = (start+end)/2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);
	return min(p1, p2); // mudar
}

int main(){
	//cout << "Seg Tree const update, range query" << endl;

	int n, q;
	cin >> n >> q;
	for(int i=1; i<n+1; i++){
		cin >> a[i];
	}
	build(1, 1, n);

	while(q--){
		char c; cin >> c;
		if(c=='u'){
			int id, x;
			cin >> id >> x;
			update(1, 1, n, id, x);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;
		}
	}
}

