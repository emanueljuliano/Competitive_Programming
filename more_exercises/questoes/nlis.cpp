#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define MAX 1000005

typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
int n, m, input, s[MAX], r[MAX], r_size = 0;
unordered_map<int, int> id;

int lis() {
	vector<int> pilha;

	for(int i = 0; i < r_size; i++) {
		auto it = lower_bound(pilha.begin(), pilha.end(), r[i]);
		if(it == pilha.end()) pilha.pb(r[i]);
		else *it = r[i];
	}

	return pilha.size();
}

int main() { _
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		id[s[i]] = i;
	}

	for(int i = 0; i < m; i++) {
		cin >> input;
		if(id.find(input) != id.end()) {
			r[i] = id[input];
			r_size++;
		} else {
			m--;
			i--;
		}
	}

	cout << lis() << endl;

	return 0;
}
