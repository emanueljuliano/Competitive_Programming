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
	int k;
	cin>>n;
	cin>>k;
	set<vector<string>> teste;
	vector<string> v(n);
	map<string,int> mapa;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		mapa[v[i]]++;
	}
	ll ans=0;
	for(int i=0;i<n-1;i++)
	{

		for(int j=i+1;j<n;j++)
		{
			string d;
			for(int f=0;f<k;f++)
			{
				if(v[i][f]=='S' and v[j][f]=='E'){d.push_back('T');}
				if(v[i][f]=='S' and v[j][f]=='T'){d.pb('E');}
				if(v[i][f]=='S' and v[j][f]=='S'){d.pb('S');}

				if(v[i][f]=='E' and v[j][f]=='E'){d.pb('E');}
				if(v[i][f]=='E' and v[j][f]=='T'){d.pb('S');}
				if(v[i][f]=='E' and v[j][f]=='S'){d.pb('T');}

				if(v[i][f]=='T' and v[j][f]=='T'){d.pb('T');}
				if(v[i][f]=='T' and v[j][f]=='E'){d.pb('S');}
				if(v[i][f]=='T' and v[j][f]=='S'){d.pb('E');}

			}
			vector<string> r = {v[j], v[i], d};
			//if(mapa.count(d)) ans++;
			sort(r.begin(),r.end());
			if(teste.count(r)==0){ans+=mapa[d]; teste.insert(r);}

			//d.clear();
		}

	}
	cout<<ans<<endl;
	return 0;

}
