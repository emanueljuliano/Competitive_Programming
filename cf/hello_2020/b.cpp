#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	ll n;
	ll tam=0;
	cin >> n;
	vector <ll> v, v1, v2;
	ll ans=0;
	for(ll i=0;i<n; i++){
		ll l;
		cin >> l;
		vector <ll> s;
		ll a;
		for(ll k=0; k<l; k++){
			cin >> a;
			s.pb(a);
		}
		if(l==1)
			v.pb(a);
		else{
			ll mini = s[0];
			bool flag=false;
			for(ll j=0; j<s.size(); j++){
				if(s[j]<=mini) mini=s[j];
				else flag=true;
			}
			if(flag){
				ans += 2*(n-tam)-1;
				tam++;
			}
			else{
				sort(s.begin(), s.end());
				if(s[0]==s[s.size()-1])
					v.pb(s[0]);
				else{
					v1.pb(s[0]);
					v2.pb(s[s.size()-1]);
				}
			}
		}
	}
	//cout << ans << endl;
	sort(v.begin(), v.end());
	// unicos menores q si mesmos
	ll at =1;
	if(v.size()>0)
	for(ll i=0; i<v.size()-1; i++){
		if(v[i]!=v[i+1]){
			ans += at*((ll)v.size()-i-1);
			at=1;
		}
		else{
			at++;
		}
	}
	//cout << ans << endl;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	// menores menores que unicos
	at=0;
	if(v.size()>0)
	for(ll i=0; i<(ll)v.size(); i++){
		if(at>=v1.size())
			break;
		while(at<(ll)v1.size() and v1[at]<v[i]){
			//cout << v1[at] << " " << v[i]  << " " << at << endl;
			ans+= (ll)v.size()-i;
			at++;
		}
		if(at>=(ll)v1.size())
			break;
	}
	//cout << ans << endl;
	// menores menores que maiores
	at=0;
	if(v2.size()>0)
	for(ll i=0; i<(ll)v2.size(); i++){
		if(at>=v1.size())
			break;
		while(at<(ll)v1.size() and v1[at]<v2[i]){
			ans+= (ll)v2.size()-i;
			at++;
		}
		if(at>=v1.size())
			break;
	}
	// maiores maiores que unicos
	at=0;
	if(v2.size()>0)
	for(ll i=0; i<(ll)v2.size(); i++){
		if(at>=(ll)v.size())
			break;
		while(at<(ll)v.size() and v[at]<v2[i]){
			ans+= (ll)v2.size()-i;
			at++;
		}
		if(at>=(ll)v.size())
			break;
	}
	
	cout << ans << endl;

	exit(0);
}
