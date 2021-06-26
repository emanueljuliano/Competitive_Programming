#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

struct pt{
	int x=-1, y=-1;
	bool operator == (const pt p) const{
		return x==p.x and y==p.y;
	}
};
struct seg{
	pt p, q;
};

int n;
vector<seg> h, v;
seg ini;
pt inip;
vector<pt> ans;

void solve(pt p, seg l, int dir){
	//cout << p.x << " " << p.y << " dir " << dir << endl;
	pt inter, change;
	seg at;
	if(dir==0){ // direita
		inter = l.q, change=l.q;
		//cout << "inter " << inter.x << " " << inter.y << endl;
		at.p=inter;
		for(auto r : v) if(l.p.x<r.p.x and r.p.x < l.q.x and r.p.y<l.p.y and l.p.y<r.q.y){
			if(p.x < r.p.x and r.p.x<at.p.x) at = r, inter = {r.p.x, l.p.y};	
		}
	}
	else if(dir==2){ // esquerda
		inter = l.p, change=l.p;
		at.p=inter;
		for(auto r : v) if(l.p.x<r.p.x and r.p.x < l.q.x and r.p.y<l.p.y and l.p.y<r.q.y){
			if(p.x > r.p.x and r.p.x>at.p.x) at = r, inter = {r.p.x, l.p.y};	
		}
	}
	else if(dir==1){ // cima
		inter = l.q, change=l.q;
		at.p=inter;
		for(auto r : h) if(l.p.y<r.p.y and r.p.y < l.q.y and r.p.x<l.p.x and l.p.x<r.q.x){
			if(p.y < r.p.y and r.p.y < at.p.y) at = r, inter = {l.p.x, r.p.y};	
		}
	}
	else if(dir==3){ // baixo
		inter = l.p, change=l.p;
		at.p=inter;
		for(auto r : h) if(l.p.y<r.p.y and r.p.y < l.q.y and r.p.x<l.p.x and l.p.x<r.q.x){
			if(p.y > r.p.y and r.p.y > at.p.y) at = r, inter = {l.p.x, r.p.y};	
		}	
	}

	if(inter==inip) return;
	ans.pb(inter);
	if(inter==change) solve(inter, l, (dir+2)%4);
	else solve(inter, at, (dir+1)%4);
}

int main(){ _
	int t; cin >> n >> t;
	for(int i=0;i <n; i++){
		pt p, q; cin >> p.x >> p.y >> q.x >> q.y;
		if(inip.x==-1) inip=p;
		seg l;
		if(p.x==q.x){
			if(p.y>q.y) swap(p, q);
			l.p=p, l.q=q;
			v.pb(l);
		}
		else{
			if(p.x>q.x) swap(p, q);
			l.p=p, l.q=q;
			h.pb(l);
		}
		if(ini.p.x==-1) ini = l;
	}

	int dir;
	if(ini.p.x==ini.q.x){
		if(inip==ini.p) dir = 1;
		else dir = 3;
	}
	else{
		if(inip==ini.p) dir = 0;
		else dir = 2;
	}
	ans.pb(inip);
	solve(inip, ini, dir);

	ll tot = 0;
	for(int i=0; i<ans.size(); i++){
		tot += abs(ans[(i+1)%ans.size()].x - ans[i].x) 
			+ abs(ans[(i+1)%ans.size()].y - ans[i].y);
	}
	t = t%tot;
	ll at = 0;
	for(int i=0; i<ans.size(); i++){
		pt p = ans[i], q = ans[(i+1)%ans.size()];
		ll dist = abs(q.x - p.x) + abs(q.y - p.y);
		if(at+dist>=t){	
			if(p.x==q.x){
				if(p.y<q.y) return cout << p.x << " " << p.y+t-at << endl, 0;
				else return cout << p.x << " " << p.y-(t-at) << endl, 0;
			}
			else{
				if(p.x<q.x) return cout << p.x+t-at << " " << p.y << endl, 0;
				else return cout << p.x-(t-at) << " " << p.y << endl, 0;
			}
		}
		at+=dist;
	}
	

	
	exit(0);
}
