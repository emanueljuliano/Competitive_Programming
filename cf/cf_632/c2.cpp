#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
#define me0(a) memset(a,0,sizeof(a))
#define me1(a) memset(a,-1,sizeof(a))
#define op freopen("in.txt","r",stdin);
#define read(a) scanf("%d",&a)
const int INF = 0x3f3f3f3f;
typedef long long LL;
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
const int maxn = 2e5 + 100;
const int MOD = 1e9+7;

int n,a[maxn];
unordered_map<int,int>mp;

int main(){
//    op;
    read(n);
    fo(i,1,n) read(a[i]);
    int sum=0;
	LL ans=0;
	int rig=-1;
    mp[0]=0;
    fo(i,1,n){
		if(a[i]<0 or sum<0) sum = (sum+a[i]+MOD)%MOD;
        else sum = (sum+a[i])%MOD;

        if(mp.count(sum)) rig=max(rig,mp[sum]);
        ans+=rig+1;
        mp[sum]=i;
    }

    ans=1LL*n*(n+1)/2-ans;
    printf("%lld\n",ans);

    return 0;

}
