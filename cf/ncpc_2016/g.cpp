#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	string s; cin >> s;
	int rank = 25, star = 0, bonus = 0, consec = 0;
	vector<int> nstars(26);
	for (int i=21; i<=25; i++) nstars[i] = 2;
	for (int i=16; i<=20; i++) nstars[i] = 3;
	for (int i=11; i<=15; i++) nstars[i] = 4;
	for (int i=1; i<=10; i++) nstars[i] = 5;

	for (auto c : s) {
		if (rank < 6) bonus = 0;
		if (c == 'W') {
			consec++;
			if (consec >= 3 and rank >= 6) bonus = 1;
			star += 1 + bonus;
			if (star > nstars[rank]) {
				if (star-1 > nstars[rank]) star = 2;
				else star = 1;
				rank--;
			}
		}
		else {
			bonus = 0, consec = 0;
			if (rank > 20 or (rank == 20 and star == 0)) continue;
			star--;
			if (star < 0) {
				rank++;
				star = nstars[rank]-1;
			}
		}
		//cout << c << " " << star << " " << rank << endl;
		if (rank <= 0) return cout << "Legend" << endl, 0;
	}
	cout << rank << endl;
	
	
	
	exit(0);
}
