#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,el,head[maxn],to[maxn],nxt[maxn],id[maxn],u[maxn],v[maxn],lim[maxn],ans[maxn];
vector<int> vec[maxn];
inline void add(int u,int v,int w){
	to[++el]=v;nxt[el]=head[u];head[u]=el;id[el]=w;
}
bool dfs(int u,int f,int x){
	if(u==v[x]) return true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		if(dfs(v,u,x)){
			ans[id[i]]=max(ans[id[i]],lim[x]);
			vec[x].push_back(id[i]);
			return true;
		}
	}
	return false;
}
int main(){
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v,i);add(v,u,i);
	}
	m=read();
	FOR(i,1,m){
		u[i]=read();v[i]=read();lim[i]=read();
		dfs(u[i],0,i);
	}
	FOR(i,1,m){
		int mn=1e9;
		FOR(j,0,(int)vec[i].size()-1) mn=min(mn,ans[vec[i][j]]);
		if(mn!=lim[i]) return puts("-1"),0;
	}
	FOR(i,1,n-1) printf("%d ",max(1,ans[i]));
}
