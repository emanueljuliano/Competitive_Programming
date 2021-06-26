  #include<bits/stdc++.h>

 #define f first
#define s second
 #define pb push_back
 #define read(x) for(auto& qw : (x)) cin >> qw;

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		vector<ll> original(n);
		vector<ll> desejo(n);
		vector<ll> pintores (m);
		read(original);
		read(desejo);
		read(pintores);
		int ii=-1;
		for(int i=0;i<n;i++){
			if(desejo[i]==pintores[m-1]){
				ii=i+1;
			}
		}
		if(ii==-1){cout<<"NO"<<endl;}
		else{
			map<ll,queue<ll> > mapa;
			int quantos=0;
			for(int i=0;i<n;i++){
				if(original[i]!=desejo[i]){
					mapa[desejo[i]].push(i+1);
					//if(desejo[i] == pintores[m-1]) ii = i+1;
					if(mapa[desejo[i]].size()==1){
						quantos++;
					}
				}
			}
			vector<ll> ans;
			for(int i=0;i<m;i++){
				if(mapa[pintores[i]].size()==0){
					ans.pb(ii);
				}
				else{
					ans.pb(mapa[pintores[i]].front());
					mapa[pintores[i]].pop();
					if(mapa[pintores[i]].size()==0){
						quantos--;
					}
				}
			}
			if(quantos==0){
				cout<<"YES"<<endl;
				for(int i=0;i<ans.size();i++){
					cout<<ans[i]<<" ";
				}
				cout<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}

