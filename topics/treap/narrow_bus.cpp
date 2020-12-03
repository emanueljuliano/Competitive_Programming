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

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

template<typename T> struct treap {
	struct node {
		node *l, *r;
		int p, sz;
		T val;
		node(T v) : l(NULL), r(NULL), p(rng()), sz(1), val(v) {}
		void update() {
			sz = 1;
			if (l) sz += l->sz;
			if (r) sz += r->sz;
		}
	};

	node* root;

	treap() { root = NULL; }
	treap(const treap& t) {
		throw logic_error("Nao copiar a treap!");
	}
	~treap() {
		vector<node*> q = {root};
		while (q.size()) {
			node* x = q.back(); q.pop_back();
			if (!x) continue;
			q.push_back(x->l), q.push_back(x->r);
			delete x;
		}
	}

	int size(node* x) { return x ? x->sz : 0; }
	int size() { return size(root); }
	void join(node* l, node* r, node*& i) { // assume que l < r
		if (!l or !r) return void(i = l ? l : r);
		if (l->p > r->p) join(l->r, r, l->r), i = l;
		else join(l, r->l, r->l), i = r;
		i->update();
	}
	void split(node* i, node*& l, node*& r, T v) {
		if (!i) return void(r = l = NULL);
		if (i->val < v) split(i->r, i->r, r, v), l = i;
		else split(i->l, l, i->l, v), r = i;
		i->update();
	}
	int count(node* i, T v) {
		if (!i) return 0;
		if (i->val == v) return 1;
		if (v < i->val) return count(i->l, v);
		return count(i->r, v);
	}
	void index_split(node* i, node*& l, node*& r, int v, int key = 0) {
		if (!i) return void(r = l = NULL);
		if (key + size(i->l) < v) index_split(i->r, i->r, r, v, key+size(i->l)+1), l = i;
		else index_split(i->l, l, i->l, v, key), r = i;
		i->update();
	}
	int count(T v) {
		return count(root, v);
	}
	void insert(T v) {
		if (count(v)) return;
		node *L, *R;
		split(root, L, R, v);
		node* at = new node(v);
		join(L, at, L);
		join(L, R, root);
	}
	void erase(T v) {
		node *L, *M, *R;
		split(root, M, R, v+1), split(M, L, M, v);
		if (M) delete M;
		M = NULL;
		join(L, R, root);
	}
	void push_back(T v){	
		insert(v);
		node *L, *R;
		split(root, L, R, v);
		join(R, L, root);
	}
	void query(T v){
		node *L, *R;
		split(root, L, R, v);
		int a = size(L) + 1;
		int b = size(R);
		cout << a << " " << b << endl;
		join(R, L, root);
		erase(v);
	}
};


int main(){ _
	int n; cin >> n;
	treap<int> t;
	int p = 1;
	while(n--){
		char c; cin >> c;
		if(c=='F') t.insert(p++);	
		else if(c=='B') t.push_back(p++);
		else{
			int a; cin >> a;
			t.query(a);
		}
	}
	
	
	
	exit(0);
}
