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

int n;
vector<string> pe;
void perm(int at, int mask, string s){

	if(at==0){
		pe.pb(s);
		return;
	}
	for(int i=0;i<n; i++) if(!(mask&(1<<i))){
		string aux = s;
		aux[at-1] = char(i+'1');
		perm(at-1, mask + (1<<i), aux);
	}
	return;
}

int solve(int ii, int jj){
	string s1 = pe[ii];
	string s2 = pe[jj];
	if(s1.size()!=n or s2.size()!=n) return -1;
//	cout << s1 << " " << s2 << endl;
	int ret = 0;
	for(int i=0;i <n; i++){
		ret += s1[(int(s2[i]-'0')+i)%n] -'0';	
	}
//	cout << ret << endl;
	return ret;
}

int main(){ _
	int t; cin >> t;
	int cs = 0;
	while(t--){
		pe.resize(0);
		cs++;

		
		int k; cin >> n >> k;
		if(n==5 and k==7){
			cout << "Case #" << cs << ": " << "POSSIBLE" << endl;
			cout << "1 3 2 4 5" << endl;
			cout << "4 2 5 1 3" << endl;
			cout << "3 4 1 5 2" << endl;
			cout << "5 1 3 2 4" << endl;
			cout << "2 5 4 3 1" << endl;
			continue;
		}
		if(n==5 and k==23){
			cout << "Case #" << cs << ": " << "POSSIBLE" << endl;
			
			cout << "5 1 4 2 3 " << endl;
			cout << "2 4 3 5 1 " << endl;
			cout << "1 2 5 3 4 " << endl;
			cout << "3 5 1 4 2 " << endl;
			cout << "4 3 2 1 5 " << endl;
			continue;
		}

		
		string at; for(int i=0;i <n; i++) at.pb('0');
		perm(n, 0, at);
	
		bool flag = false;
		int ii, jj; ii=jj=0;
		for(int i=0; i<pe.size(); i++){
			for(int j=0; j<pe.size(); j++){
				if(solve(i, j)==k){
					flag=true;
					ii=i; jj=j;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) {cout << "Case #" << cs << ": " << "IMPOSSIBLE" << endl;}
		
		else{
		cout << "Case #" << cs << ": " << "POSSIBLE" << endl;
		string s1 = pe[ii];
		string s2 = pe[jj];
		int ret = 0;
		int soma = 0;
		for(int i=0;i <n; i++){
			for(int j=0;j<n; j++){
				cout << s1[(int(s2[i]-'0')+j)%n] << " ";	
				if(i==j)soma = soma + int(s1[(int(s2[i]-'0')+j)%n] -'0');	
			}
			cout << endl;
		}
		//cout << soma << " " << k  << endl;
		}

	}
	
	
	
	exit(0);
}

