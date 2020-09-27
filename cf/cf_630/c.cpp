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
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		string s; cin >> s;
		int ans = 0;
		vector<int> v(27, 0);
		for(int i=0; i<k; i++){
			for(int j=0; j<27; j++) v[j]=0;
			for(int j=i; j<n; j+=k){
				//cout << j << " " << j-i+k-i-1 << " " << s[j] << " " << s[j-i+k-i-1] << endl;
				v[s[j]-'a']++; v[s[j-i+k-i-1]-'a']++;
			}
			int maxi = 0; int l = 0;
			for(int j=0; j<27; j++){
				if(v[j]>maxi) maxi = v[j], l=j;
			}
			for(int j=i; j<n; j+=k){
				char c = char(l+'a');
				if(s[j]!=c) ans++, s[j]=c;
				if(s[j-i+k-i-1]!=c) ans++; s[j-i+k-i-1]=c;
			}
			
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
