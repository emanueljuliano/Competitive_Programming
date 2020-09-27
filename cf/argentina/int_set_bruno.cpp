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

typedef int int_set_type; // mudar aqui se quiser long long
template<int_set_type N, bool MULTI = false> struct int_set {
	using ist = int_set_type;
	struct node {
		node *l, *r;
		int cnt;
		node() : l(NULL), r(NULL), cnt(0) {}
		void update() {
			cnt = 0;
			if (l) cnt += l->cnt;
			if (r) cnt += r->cnt;
		}
	};

	node* root;

	int_set() { root = NULL; }
	int_set(node* x) { root = x; }
	int_set(const int_set& t) {
		throw logic_error("Nao copiar o int_set!");
	}
	~int_set() {
		vector<node*> q = {root};
		while (q.size()) {
			node* x = q.back(); q.pop_back();
			if (!x) continue;
			q.push_back(x->l), q.push_back(x->r);
			delete x;
		}
	}

	int count(node* x) { return x ? x->cnt : 0; }

	node* insert(node* at, ist idx, ist l, ist r) {
		if (!at) at = new node();
		if (l == r) {
			if (!MULTI) at->cnt = 0;
			return at->cnt++, at;
		}
		ist m = l + (r-l)/2;
		if (idx <= m) at->l = insert(at->l, idx, l, m);
		else at->r = insert(at->r, idx, m+1, r);
		return at->update(), at;
	}
	void insert(ist v) {
		assert(v >= 0 and v <= N);
		root = insert(root, v, 0, N);
	}

	node* erase(node* at, ist idx, ist l, ist r) {
		if (!at) return at;
		if (l == r) at->cnt--;
		else {
			ist m = l + (r-l)/2;
			if (idx <= m) at->l = erase(at->l, idx, l, m);
			else at->r = erase(at->r, idx, m+1, r);
		}
		at->update();
		if (!at->cnt) return delete at, NULL;
		return at;
	}
	void erase(ist v) {
		if (v < 0 or v > N) return;
		root = erase(root, v, 0, N);
	}

	int size() { return root ? root->cnt : 0; }

	int count(ist v) {
		if (v < 0 or v > N) return 0;
		node* at = root;
		ist l = 0, r = N;
		while (1) {
			if (!at) return 0;
			if (l == r) return at->cnt;
			ist m = l + (r-l)/2;
			if (v <= m) at = at->l, r = m;
			else at = at->r, l = m+1;
		}
	}

	int count(node* at, ist a, ist b, ist l, ist r) {
		if (!at or b < l or r < a) return 0;
		if (a <= l and r <= b) return at->cnt;
		ist m = l + (r-l)/2;
		return count(at->l, a, b, l, m) + count(at->r, a, b, m+1, r);
	}
	int order_of_key(ist v) {
		if (v <= 0) return 0;
		if (v > N) return size();
		return count(root, 0, v-1, 0, N);
	}

	const ist operator [](int i) {
		assert(i >= 0 and i < size());
		node* at = root;
		ist l = 0, r = N;
		while (l < r) {
			ist m = l + (r-l)/2;
			if (count(at->l) > i) at = at->l, r = m;
			else {
				i -= count(at->l);
				at = at->r; l = m+1;
			}
		}
		return l;
	}

	node* merge(node* l, node* r) {
		if (!l or !r) return l ? l : r;
		if (!l->l and !l->r) { // folha
			if (MULTI) l->cnt += r->cnt;
			delete r;
			return l;
		}
		l->l = merge(l->l, r->l), l->r = merge(l->r, r->r);
		l->update(), delete r;
		return l;
	}
	void merge(int_set<N, MULTI>& s) {
		root = merge(root, s.root);
		s.root = NULL;
	}
/*
	node* split(int i) {
		if (v <= 0) return NULL;

	}
	node* split(ist v) {
	}

*/
};

void print(auto& s) {
	for (int i = 0; i < s.size(); i++) cout << s[i] << " ";
	cout << endl;
}

int main() { _
	int_set<30> s;
	s.insert(10);
	s.insert(10);
	s.insert(20);
	s.insert(30);
	print(s);
	int_set<30> t;
	t.insert(10);
	t.insert(5);
	t.insert(15);
	t.insert(21);
	print(t);
	s.merge(t);
	print(s);
	print(t);
	exit(0);
}
