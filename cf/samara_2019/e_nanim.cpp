#include<bits/stdc++.h>

#define f first
#define s second
#define pb push_back


using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;



int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll m;
	cin>>n>>m;
	vector<pair<ll,pair<ll,ll> > > v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first;
		cin>>v[i].second.first;
		v[i].second.second=i+1;
	}
	sort(v.begin(),v.end());
	ll limite =1;
	ll indice ;
	ll ultimo=0;
	ll primeiro=0;
	vector<int> ans;
	ll aa;
	ll bb;
	ll cc;
	for(int i=0;i<n;i++)
	{
		aa = v[i].f;
		bb = v[i].s.f;
		cc=  v[i].s.s;
		/*if(limite==aa){
		  if(ultimo>bb){
		  ans.pb(indice); limite=ultimo+1;
		  } 
		  else{
		  ans.pb(cc); limite=bb+1;
		  }  
		  }*/

		if (limite<aa and ultimo<limite){
			cout<<"NO"<<endl; return 0;
		}
		else if (limite<aa and ultimo>=limite){
			limite=ultimo+1; ans.pb(indice);
		}
		if(limite<aa){cout << "NO" << endl; return 0;}
		if(bb>ultimo){
			indice=cc; ultimo=bb;
		}
	}
	if(ultimo>=limite){limite=ultimo+1; ans.pb(indice);}
	if(limite==m+1)
	{
		cout<<"YES"<<endl;
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}


	return 0;
}
