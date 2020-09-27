#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_withstdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

map<pair<int,int>,int> memo;

int brute(int i, int j) {
	if(memo.count({i,j})) return memo[{i,j}];
	if(j < 0 or j > i) return 0;
	if(!i and !j) return 1;
	else return memo[{i,j}] = brute(i-1, j-1) + brute(i-1, j);
}

int main(){ 

	int last = 0;
	for(int i = 0; i < 100; i++) {
		int ret = 0;
		for(int j=0; j<=i; j++) if(brute(i,j) % 2 == 0) ret++;
		//int val = i ^ ((1 << ((int) floor(log2(i)))) - 1);
		cout << fixed << setw(5) << i << "   " << ret << "   " << ret - last << endl;
		last = ret;
	}

	return 0;
}
