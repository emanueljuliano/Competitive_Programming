#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define ss second
#define ff first

typedef long long ll;
typedef pair<ll, ll> pii;


int main(){ _

	ll tt;
	cin >> tt;
	for(ll ii=0; ii<tt; ii++){
		ll n, t, a, b;
		cin >> n >> t >> a >> b;
		vector<ll> dif, time;
		ll fac=0;
		for(ll i=0; i<n; i++){
			ll c;
			cin >>c;
			if(c==0) fac++;
			dif.pb(c);
		}	
		for(ll i=0; i<n; i++){
			ll c;
			cin >>c;
			time.pb(c);
		}
		vector< pii > v;
		for(ll i=0; i<n; i++){
			v.pb({time[i], dif[i]});
		}
		sort(v.begin(), v.end());
		ll ans=0;
		ll at=0;
		vector<ll> resp;
		for(ll i=0; i<n; i++){
			if(v[i].ss==0){
				fac--;
				ans+=1;
				at+=a;
				if(at<=t and (i==n-1 or at<v[i+1].ff))
					resp.pb(ans);
			}
			else{	
				ll res=0;
				if(v[i].ff-at > 0 and fac>0){
					if((v[i].ff-1-at)/a>fac)
						res=ans+fac;
					else{
						res=ans+ (v[i].ff-1-at)/a;
					}
				}
				ans+=1;
				at+=b;
				resp.pb(res);
				if(at<=t and (i==n-1 or at<v[i+1].ff))
					resp.pb(ans);
			}
		}
		ll maxi = 0;
		for(ll i=0; i<resp.size(); i++){
			maxi = max(maxi, resp[i]);
		}
		cout << maxi << endl;
	}

	exit(0);
}
