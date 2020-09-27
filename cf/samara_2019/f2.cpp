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

int ans1=0, ans2=1, ans=0;
void change(int val, int id1, int id2){
	if(id1==id2) return;
	if(val<ans) return;
	ans = val;
	ans1 = id1;
	ans2 = id2;
}

int main(){ _
	int n; cin >> n;
	vector<ii> A, H, ent;
	for(int i=0;i <n; i++){
		int a, b; cin >> a >> b;
		A.pb({a, i});
		H.pb({b, i});
		ent.pb({a, b});
	}
	sort(A.begin(), A.end()); sort(H.begin(), H.end());
	
	int maxi = 0, maxi2 = 0, id1=0, id2=0;
	int it1=0, it2=0;
	for(; it1<n; it1++){
		int a = A[it1].f, id=A[it1].s;
		while(it2<n and a>=H[it2].f){
			int h = H[it2].f, ind = H[it2].s;
			int at = ent[ind].f;
			if(at>maxi){
				maxi2 = maxi, id2 = id1;
				maxi = at, id1 = ind;
			}
			else if(at > maxi2){
				maxi2 = at, id2 = ind;
			}
			it2++;
		}
		change(maxi, id, id1);
		change(maxi2, id, id2);
		if(maxi >=ent[id].s){
			change(maxi+a, id, id1);
		}
		if(maxi2 >= ent[id].s){
			change(maxi2+a, id, id2);
		}
	}	
	cout << ans << endl;
	cout << ans1+1 << " " << ans2+1 << endl;
	
	exit(0);
}
