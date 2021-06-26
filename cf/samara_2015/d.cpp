#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int n;
int cnt[3030];
int ganha(vector<int>& a, vector<int>& b) {
	int qt = 0;
	int it = 0;
	for (int i : a) {
		while(it<b.size() and i>b[it]) it++;
		qt += it;
	}
	if(2*qt == a.size()*b.size()) return 0;
	else if(2*qt > a.size()*b.size()) return 1;
	else return -1;
}

void ord(vector<int>& a){
	for(int i : a) cnt[i]++;
	int it = 0;
	for(int i=0;i <=n; i++) if(cnt[i]) cnt[i]--, a[it++] = i;
}

int main() { _
	cin >> n;
	if(n<3) return cout << "FAIL" << endl, 0;
	vector<int> a(n), b(n), c(n);
	n *= 3;
	vector<int> v(n);
	iota(v.begin(), v.end(), 1);
	while(true){
		shuffle(v.begin(), v.end(), rng);
		for(int i=0;i <n/3; i++) a[i] = v[i];
		for(int i=n/3;i <2*n/3; i++) b[i-n/3] = v[i];
		for(int i=2*n/3;i <n; i++) c[i-2*n/3] = v[i];
		ord(a), ord(b), ord(c);

		/*for(auto u : a) cout << u << " ";
		cout << endl;
		for(auto u : b) cout << u << " ";
		cout << endl;
		for(auto u : c) cout << u << " ";
		cout << endl;
		cout << endl;*/
		int ab = ganha(a, b), ac = ganha(a, c), bc = ganha(b, c);
		if(ab>=0 and ac>=0) continue;
		if(-ab>=0 and bc>=0) continue;
		if(-ac>=0 and -bc>=0) continue;
		break;
	}

	cout << "WIN" << endl;
	for(auto u : a) cout << u << " ";
	cout << endl;
	for(auto u : b) cout << u << " ";
	cout << endl;
	for(auto u : c) cout << u << " ";
	cout << endl;

	exit(0);
}
