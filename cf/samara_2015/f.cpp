#include<bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

int M[55][1010];

int main(){ _
	int n, m; cin >> n >> m;
	vector<string> names(n);
	vector<int> cap(n);
	for(auto &i : cap) cin >> i;
	for(auto &i : names) cin >> i;

	for(int i=0;i <n; i++) {
		string s; cin >> s;
		for(int j=0; j<m; j++) M[i][j] = (s[j]=='1');
	}
	int ans = -1;
	vector<int> v(3);
	for(int i=0;i <n; i++) for(int j=i+1; j<n; j++) for(int k=j+1; k<n; k++){
		int a = cap[i], b = cap[j], c = cap[k];
		int at = 0, all = 0, ab = 0, ac = 0, bc = 0;
		//cout << "i, j, k " << i << " " << j << " " << k << endl;

		for(int l=0; l<m; l++){
			if(M[i][l] and M[j][l] and M[k][l]) all++;
			else if(M[i][l] and M[j][l]) ab++;
			else if(M[i][l] and M[k][l]) ac++;
			else if(M[j][l] and M[k][l]) bc++;
			else if(M[i][l] and a) a--, at++;
			else if(M[j][l] and b) b--, at++;
			else if(M[k][l] and c) c--, at++;
		}
		//cout << "a, b, c, ab, ac, bc, all " << a << " " << b << " " << c << " " << ab << " "<< ac << " " << bc << " " << all << endl;
		for(int l=0; l<=ab; l++) if(l<=a){
			int a2 = a-l, b2 = max(0, b-(ab-l)), c2 = c, c3 = c;
			int cur = a-a2 + b-b2;
			if(ac >= a2){
				c2 = max(0, c-(ac-a2));
				cur += a2 + (c-c2);
				a2 = 0;
			}
			else cur += ac, a2 -= ac;
			c3 = c2;
			if(bc >= b2){
				c3 = max(0, c2-(bc-b2));
				cur += b2 + (c2-c3);
				b2 = 0;
			}
			else cur += bc, b2 -= bc;
			cur += min(all, a2+b2+c3);
			if(at+cur>ans){

				ans = at+cur;
				v[0] = i, v[1] = j, v[2] = k;
			}
			//cout << a2 << " " << b2 << " " << c3 << endl;
			//cout << "l, cur " << l << " " << cur << endl;
		}
	}
	
	cout << ans << endl;
	cout << names[v[0]] << " " << names[v[1]] << " " << names[v[2]] << endl;

}
