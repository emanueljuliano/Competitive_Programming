#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define pb push_back

int p;
bool tp = false;

vector<vector<vector<int>>> val;
int fs(string s){
	int at = 1, ret = 0;
	if(s.size()>5) return -1;
	if(s.size()>1 and s[0]=='0') return -1;
	for(int i=s.size()-1; i+1; i--)
		ret += at*(s[i]-'0'), at*=10;
	return ret;
}
int f(string s){
	if(tp) return fs(s);
	int at = 1, ret = 0;
	if(s.size()>=4) return -1;
	if(s.size()>1 and s[0]=='0') return -1;
	for(int i=s.size()-1; i+1; i--)
		ret += at*(s[i]-'0'), at*=10;
	return ret;
}

vector<vector<int>> f1(string s, int ini){
	vector<vector<int>> ret;
	for(int i=ini+1;i <s.size();i++){
		vector<int> vat;
		int a1 = f(s.substr(ini, i-ini));
		int soma = fs(s.substr(i, s.size()-i));
		if(a1<0 or soma<0) continue;
		if(a1==soma){
			vat.pb(ini), vat.pb(i); ret.pb(vat);
		}
	}
	return ret;
}
vector<vector<int>> f2(string s, int ini){
	vector<vector<int>> ret;
	for(int i=ini+1;i <s.size();i++) for(int j=i+1; j<s.size(); j++){
		vector<int> vat;
		int a1 = f(s.substr(ini, i-ini)), a2 = f(s.substr(i, j-i));
		int soma = fs(s.substr(j, s.size()-j));
		if(a1<0 or a2<0 or soma<0) continue;
		if(a1+a2==soma){
			vat.pb(ini), vat.pb(i), vat.pb(j); ret.pb(vat);
		}
	}
	return ret;
}
vector<vector<int>> f3(string s, int ini){
	vector<vector<int>> ret;
	for(int i=ini+1;i<s.size();i++)for(int j=i+1; j<s.size(); j++)for(int k=j+1; k<s.size(); k++){
		vector<int> vat;
		int a1 = f(s.substr(ini, i-ini)), a2 = f(s.substr(i, j-i)), a3 = f(s.substr(j, k-j));
		int soma = fs(s.substr(k, s.size()-k));
		if(a1<0 or a2<0 or a3<0 or soma<0) continue;
		if(a1+a2+a3==soma){
			vat.pb(ini), vat.pb(i), vat.pb(j), vat.pb(k); ret.pb(vat);
		}
	}
	return ret;
}
vector<vector<int>> f4(string s, int ini){
	vector<vector<int>> ret;
	for(int i=ini+1;i<s.size();i++)for(int j=i+1; j<s.size(); j++)for(int k=j+1; k<s.size(); k++)
	 for(int l=k+1; l<s.size(); l++){
		vector<int> vat;
		int a1 = f(s.substr(ini, i-ini)), a2 = f(s.substr(i, j-i)), a3 = f(s.substr(j, k-j)),
		 a4 = f(s.substr(k, l-k));
		int soma = fs(s.substr(l, s.size()-l));
		if(a1<0 or a2<0 or a3<0 or a4<0 or soma<0) continue;
		if(a1+a2+a3+a4==soma){
			vat.pb(ini), vat.pb(i), vat.pb(j), vat.pb(k), vat.pb(l); ret.pb(vat);
		}
	}
	return ret;
}
vector<vector<int>> f5(string s, int ini){
	vector<vector<int>> ret;
	for(int i=ini+1;i<s.size();i++)for(int j=i+1; j<s.size(); j++)for(int k=j+1; k<s.size(); k++)
	 for(int l=k+1; l<s.size(); l++)  for(int m=l+1; m<s.size(); m++) {
		vector<int> vat;
		int a1 = f(s.substr(ini, i-ini)), a2 = f(s.substr(i, j-i)), a3 = f(s.substr(j, k-j)),
		 a4 = f(s.substr(k, l-k)), a5 = f(s.substr(l, m-l));

		int soma = fs(s.substr(m, s.size()-m));
		if(a1<0 or a2<0 or a3<0 or a4<0 or a5<0 or soma<0) continue;
		if(a1+a2+a3+a4+a5==soma){
			vat.pb(ini), vat.pb(i), vat.pb(j), vat.pb(k), vat.pb(l), vat.pb(m); ret.pb(vat);
		}
	}
	return ret;
}

vector<vector<int>> solve1(string s){
	vector<vector<int>> ret(1);
	for(int i=0;i <s.size(); i++){
		if(i!=0) ret[0].pb(i);
		while(i<s.size() and (s[i]>'9' or s[i]<'0')) i++;
	}
	p = ret[0].size();
	ret[0].pb(s.size());
	return ret;
}

vector<vector<int>> solve(string s){
	vector<vector<int>> ret;
	int ini = 0;
	while(s[ini]>'9') ini++;
	if(p==1) ret = f1(s, ini);
	if(p==2) ret = f2(s, ini);
	if(p==3) ret = f3(s, ini);
	if(p==4) ret = f4(s, ini);
	if(p==5) ret = f5(s, ini);

	return ret;
}

vector<vector<int>> ids(vector<vector<vector<int>>> v, vector<string> vs){
	vector<vector<int>> ret;
	ret.pb(v[0][0]);
	int p2 = v.size()-2;
	if(p2 == 1){
		for(int i1=0;i1 <val[1].size(); i1++) for(int i2=0; i2<val[2].size(); i2++){
			vector<int> w = val[1][i1], t = val[2][i2];
			vector<int> sums(p+1); vector<int> tot(p+1);
			for(int i = 0; i<w.size(); i++) sums[i]+=w[i];
			for(int i = 0; i<t.size(); i++) tot[i]+=t[i];
			
			if(sums==tot){
				ret.pb(w), ret.pb(t); return ret;
			}
		}
	}
	if(p2 == 2){
		for(int i1=0;i1 <val[1].size(); i1++) for(int i2=0; i2<val[2].size(); i2++)
			for(int i3 = 0; i3<val[3].size(); i3++){
			vector<int> w = val[1][i1], x = val[2][i2], t = val[3][i3];
			vector<int> sums(p+1); vector<int> tot(p+1);
			for(int i = 0; i<w.size(); i++) sums[i]+=w[i];
			for(int i = 0; i<x.size(); i++) sums[i]+=x[i];
			for(int i = 0; i<t.size(); i++) tot[i]+=t[i];
			
			if(sums==tot){
				ret.pb(w), ret.pb(x), ret.pb(t); return ret;
			}
		}
	}
	if(p2 == 3){
		for(int i4=0; i4<val[4].size(); i4++)
		for(int i1=0;i1 <val[1].size(); i1++) 
		for(int i2=0; i2<val[2].size(); i2++)
		for(int i3 = 0; i3<val[3].size(); i3++){ 
			vector<int> w = val[1][i1], x = val[2][i2], y = val[3][i3], t = val[4][i4];
			vector<int> sums(p+1); vector<int> tot(p+1);
			for(int i = 0; i<w.size(); i++) sums[i]+=w[i];
			for(int i = 0; i<x.size(); i++) sums[i]+=x[i];
			for(int i = 0; i<y.size(); i++) sums[i]+=y[i];
		
			if(t != sums) continue;
			ret.pb(w), ret.pb(x), ret.pb(y), ret.pb(t); return ret;
		}
	}
	if(p2 == 4){
		for(int i5=0; i5<val[5].size(); i5++)
		for(int i1=0;i1 <val[1].size(); i1++){ 
		stop1: if(i1==val[1].size()) break;
		for(int i2=0; i2<val[2].size(); i2++){
		stop2: if(i2==val[2].size()) break;
		for(int i3 = 0; i3<val[3].size(); i3++){
		stop3: if(i3==val[3].size()) break;
		for(int i4=0; i4<val[4].size(); i4++){
			vector<int> w = val[1][i1], x = val[2][i2], y = val[3][i3],
			z = val[4][i4], t = val[5][i5];
			vector<int> sums(p+1); vector<int> tot(p+1);
			
			for(int i = 0; i<w.size(); i++) sums[i]+=w[i];
			for(int i=0;i <sums.size(); i++) if(sums[i]>t[i]) {i1++; goto stop1;}
			for(int i = 0; i<x.size(); i++) sums[i]+=x[i];
			for(int i=0;i <sums.size(); i++) if(sums[i]>t[i]) {i2++; goto stop2;}
			for(int i = 0; i<y.size(); i++) sums[i]+=y[i];
			for(int i=0;i <sums.size(); i++) if(sums[i]>t[i]) {i3++; goto stop3;}
			for(int i = 0; i<z.size(); i++) sums[i]+=z[i];
			if(t!=sums) continue;
			ret.pb(w), ret.pb(x), ret.pb(y), ret.pb(z), ret.pb(t); return ret;
		}}}}
	}
	return ret;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		val.clear();
		vector<vector<vector<int>>> v;
		vector<string> vs;
		while(true){
			tp = false;
			vector<vector<int>> w;
			string s; cin >> s;
			if(s[0]=='T' and s[1]=='P') tp=true;
			vs.pb(s);
			if(v.empty()) w = solve1(s);
			else w = solve(s);
			vector<vector<int>> vv;
			for(auto x : w){
				vector<int> vvv;
				x.pb(s.size());
				for(int i = 0; i<x.size()-1; i++) vvv.pb(fs(s.substr(x[i], x[i+1]-x[i])));
				vv.pb(vvv);
			}
			
			v.pb(w); val.pb(vv);
			if(tp) break;
		}
		vector<vector<int>> ans = ids(v, vs);
		string sa = vs[0];
		cout << sa.substr(0, ans[0][0]);
		for(int j=0; j<ans[0].size()-1; j++){
			cout << " " << sa.substr(ans[0][j], ans[0][j+1]-ans[0][j]);
		}
		cout << endl;

		for(int i=1; i<ans.size(); i++){
			string s = vs[i];
			vector<int> id = ans[i];
			int ini = 0;
			while(s[ini]>'9') ini++;
			cout << s.substr(0, ini);
			for(int j=0; j<id.size(); j++){
				cout << " " << id[j];
			}
			cout << endl;
		}
	}
	exit(0);
}
