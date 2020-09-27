#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXP 10001000

int id[MAXP];
int sz[MAXP];

int find(int p){
	if (id[p] == p) return p;
	return id[p] = find(id[p]);
}

void join(int p, int q){
	p = find(p);
	q = find(q);
	if (p==q) return;
	if(sz[p] > sz[q]) swap(p, q);
	id[p]=q;
	sz[q]+= sz[p];
	return;
}

int main(){ _
	cout << "union find" << endl;

}
