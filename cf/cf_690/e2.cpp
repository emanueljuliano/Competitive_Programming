#include<bits/stdc++.h>
 
 #define f first
 #define s second
 #define pb push_back
 
 
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}
 
 
int main ()
{
    ios::sync_with_stdio(0);
cin.tie(0);
 
vector<ll> fatorial(200010) ;
fatorial[0]=1;
fatorial[1]=1;
for(ll i=2;i<=200009;i++)
{
    fatorial[i]=((fatorial[i-1])*i)%1000000007;
}
 
int t;
cin>>t;
while(t!=0)
{
    t--;
ll n;
cin>>n;
ll m;
ll k;
cin>>m>>k;
vector<ll> v(n);
for(int i=0;i<n;i++)
{
    cin>>v[i];
}
 
sort(v.begin(),v.end());
ll ans=0;
 
for(int i=0;i<n;i++)
{
    ll aux= upper_bound(v.begin()+i,v.end(),v[i]+k)-v.begin()-i-1;
 
   if(aux>=(m-1)){
   	ans+= (fatorial[aux]*inv((fatorial[m-1]*fatorial[aux-(m-1)])%1000000007,1000000007));
	ans %=int(1e9+7);
	}
}
cout<<ans%1000000007<<endl;
}
return 0;
}
