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

void radix(vector<pair<ii, int>> &a){
	int n = a.size();
	{
		vector<int> cnt(n);
		for(int i=0;i <n; i++) cnt[a[i].f.s]++;
		vector<int> pos(n);
		pos[0] = 0;
		for(int i=1; i<n; i++) pos[i] = pos[i-1] + cnt[i-1];
		vector<pair<ii, int>> a_new(n);
		for(int i=0;i <n; i++) a_new[pos[a[i].f.s]++] = a[i];
		a = a_new;
	}
	{
		vector<int> cnt(n);
		for(int i=0;i <n; i++) cnt[a[i].f.f]++;
		vector<int> pos(n);
		pos[0] = 0;
		for(int i=1; i<n; i++) pos[i] = pos[i-1] + cnt[i-1];
		vector<pair<ii, int>> a_new(n);
		for(int i=0;i <n; i++) a_new[pos[a[i].f.f]++] = a[i];
		a = a_new;
	}
}

int main(){ _
	string s; cin >> s;
	s += "$";
	int n = s.size();

	vector<int> p(n), c(n); // p=prefix, c=equivalence
	{
		// k = 0
		vector<pair<char, int>> a(n);
		for(int i=0; i<n; i++) a[i] = {s[i], i};
		sort(a.begin(), a.end());
		for(int i=0;i <n; i++) p[i] = a[i].s;
		c[p[0]] = 0;
		for(int i=1; i<n; i++){
			if(a[i].f != a[i-1].f) c[p[i]] = c[p[i-1]]+1;
			else c[p[i]] = c[p[i-1]];
		}
	}
	int k = 0;
	while(1<<k < n){
		vector<pair<ii, int>> a(n);
		for(int i=0; i<n; i++) a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
		radix(a);
		for(int i=0;i <n; i++) p[i] = a[i].s;
		c[p[0]] = 0;
		for(int i=1; i<n; i++){
			if(a[i].f != a[i-1].f) c[p[i]] = c[p[i-1]]+1;
			else c[p[i]] = c[p[i-1]];
		}
		k++;
	}
	for(int i=0;i <n; i++) cout << p[i] << " ";
	cout << endl;

	exit(0);
}
