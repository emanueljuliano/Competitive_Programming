#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

int h1, h2, a1, a2;

int time_to_kill(int h, int t) {
	int damage = 0, t2 = t;
	while (damage < h) 
		damage += t2, t2++;
	return t2 - t;
}

pair<ll, string> solve1() {
	string s; ll ret = 0;
	
	int t1 = time_to_kill(h1, 1);
	int over = t1*(t1+1)/2 - h1;
	int t2 = time_to_kill(h2-over, t1+1);
	
	for (int i=0; i<t1; i++) s += 'A', ret += a1+a2;
	for (int i=0; i<t2; i++) s += 'B', ret += a2;

	if (time_to_kill(h2, t1+1) > t2)
		s[over-1] = 'B';
	
	return {ret, s};
}

pair<ll, string> solve2() {
	string s; ll ret = 0;
	
	int t2 = time_to_kill(h2, 1);
	int over = t2*(t2+1)/2 - h2;
	int t1 = time_to_kill(h1-over, t2+1);

	for (int i=0; i<t2; i++) s += 'B', ret += a1+a2;
	for (int i=0; i<t1; i++) s += 'A', ret += a1;

	int l = 0, r = over;
	while (l < r) {
		int m = (l+r)/2;
		if (time_to_kill(h1-m, t2+1) > t1) l = m+1;
		else r = m;
	}
	
	int limit = l;
	for (int i=1; i<=t2; i++) {
		if (over > 2*i) 
			s[i-1] = 'A', over -= i, limit -= i;
		else if (i <= over and i >= limit) {
			s[i-1] = 'A'; break;
		}
	}
	
	return {ret, s};
}

int main(){ _
	int tc; cin >> tc;
	while (tc--) {
		cin >> h1 >> h2 >> a1 >> a2;
		
		auto ans1 = solve1();
		auto ans2 = solve2();
			
		if (ans1 < ans2) cout << ans1.first << " " << ans1.second << endl;
		else cout << ans2.first << " " << ans2.second << endl;
	}
	
	exit(0);
}
