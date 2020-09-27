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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 30*2e5+10;

struct trie{
	int sz[MAX];
	int node[MAX][2];
	int ptr = 1;
	trie(){}
	
	int next(int a, int b){
		if(node[a][b]==0)
			node[a][b] = ++ptr;
		return node[a][b];
	}
	void insert(int a){
		int at = 0;
		for(int i=30; i>=0; i--){
			bool b = (a&(1<<i));
			at = next(at, b);
			sz[at]++;
		}
	}
	void erase(int a){
		int at = 0;
		for(int i=30; i>=0; i--){
			bool b = (a&(1<<i));
			at = next(at, b);
			sz[at]--;
		}	
	}
	int query(int a){
		int at = 0, ret=0;
		for(int i=30; i>=0; i--){
			bool b = !(a&(1<<i));
			int aux = node[at][b];
			if(sz[aux]) ret += (1<<i), at=aux;
			else at = node[at][!b];
		}	
		return ret;
	}

};

trie t;

int main(){ _
	t.insert(0);
	int n; cin >> n;
	while(n--){
		char a; int b; cin >> a >> b;
		if(a=='+') t.insert(b);
		if(a=='-') t.erase(b);
		if(a=='?') cout << t.query(b) << endl;
	}
	
	
	
	exit(0);
}
