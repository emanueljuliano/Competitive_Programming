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


int main(){ _
	int n, q; cin >> n >> q;
	set<int> st;
	set<pair<int, ii>> dif; 
	map<int, int> cnt;
	vector<int> aux;
	
	for(int i=0;i <n; i++){
		int a; cin >> a;
		if(cnt.count(a)){
			cnt[a]++;
			continue;
		}

		st.insert(a);
		cnt[a]=1;
		aux.pb(a);
	}
	sort(aux.begin(), aux.end());

	for(int i=0; i<aux.size()-1; i++){
		dif.insert({aux[i+1]-aux[i], {aux[i], aux[i+1]}});
	}
	int ans = 0;
	if(dif.size()) ans = aux.back() - aux[0] - (*dif.rbegin()).f;
	cout << ans << endl;

	while(q--){
		int flag, x; cin >> flag >> x;
		if(flag==0){
			cnt[x]--;
			if(cnt[x]==0){
				if(st.size()==1){ 
					st.erase(x);
					ans = 0;
					cout << ans << endl;
					continue;
				}
				auto it = st.lower_bound(x);
				auto ait = it; ait--;
				auto bit = it; bit++;
				int a = *ait;
				int b = *bit;
				
				if(x == *st.begin()){
					pair<int, ii> rem = {b-x, {x, b}};
					dif.erase(rem);
				}
				else if(x == *st.rbegin()){
					pair<int, ii> rem = {x-a, {a, x}};
					dif.erase(rem);
				}
				else{
					pair<int, ii> rem1 = {b-x, {x, b}};
					pair<int, ii> rem2 = {x-a, {a, x}};
					pair<int, ii> ad = {b-a, {a, b}};
					dif.erase(rem1);
					dif.erase(rem2);
					dif.insert(ad);
				}
				st.erase(x);
				if(dif.size()) ans = *st.rbegin() - *st.begin() - (*dif.rbegin()).f;
				else ans = 0;
			}
			cout << ans << endl;
		}
		else{
			cnt[x]++;
			if(cnt[x]==1){
				if(st.size()==0){
					st.insert(x);
					cout << ans <<endl;
					continue;
				}
				
				auto it = st.lower_bound(x);
				auto ait = it; ait--;
				auto bit = it;
				int a = *ait;
				int b = *bit;
					
				st.insert(x);
				if(x==*st.begin()){
					pair<int, ii> ad = {b-x, {x, b}};
					dif.insert(ad);
				}
				else if(x==*st.rbegin()){
					pair<int, ii> ad = {x-a, {a, x}};
					dif.insert(ad);
				}
				else{
					pair<int, ii> rem = {b-a, {a, b}};
					pair<int, ii> ad1 = {b-x, {x, b}};
					pair<int, ii> ad2 = {x-a, {a, x}};
					dif.erase(rem);
					dif.insert(ad1);
					dif.insert(ad2);
				}
				ans = *st.rbegin() - *st.begin() - (*dif.rbegin()).f;
			}
			cout << ans << endl;
		}
	}
	
	exit(0);
}
