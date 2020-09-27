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
		ll n, d; cin >> n >> d;
		ll maxi = 0, mini = 0;

		ll p2 = 0;
		ll res = n;
		while(true){
			if((1<<p2)<=res){
				mini += p2* (1<<p2);
				res -=(1<<p2);
				p2++;
			}
			else{
				mini += res*p2;
				break;
			}
		}
		maxi = (n*(n-1))/2;
		if(d<mini  or  d>maxi){cout << "NO" << endl; continue;}
		cout << "YES" << endl;
		
		vector<int> pai(n, 0), sz(n, 0), filhos(n, 0);
		sz[0] = 1;
		for(int i=1; i<n; i++){
			pai[i] = i-1;
			sz[i] = i+1;
			filhos[i-1]++;
		}
		queue <int> q;
		q.push(0);
		ll at = maxi;
		int pt = n-1;
		int pt2=0;
//		cout << at << endl;
		for(int i=n-1; i>=0; i--){
			if(d<at){
				int aux = q.size();
				q.push(pt2+1);
				for(int j=0; j<aux; j++){
					int x = sz[pt];
					if(d<at - (sz[pt]-sz[q.front()]-1)){
						//cout << pt << " p " << q.front() << endl;
						filhos[pai[pt]]--;
						filhos[q.front()]++;
						pai[pt] = q.front();
						sz[pt] = sz[q.front()]+1;
						
						q.pop();
						q.push(pt);
						q.push(pt);
						
						at -= x-sz[pt];
						//cout << at << endl;
						pt--;
					}
					else{
						for(int k=0; k<n; k++){
							if(sz[k] == sz[pt] - (at-d+1) and filhos[k]<=1){
								//cout << k << " " << pt << endl;
								pai[pt] = k, sz[pt]=sz[k]+1; break;
									
							}
						}
						at =d;
						break;
					}
				}
				pt2++;	
			}
			else break;
		}
		for(int i=1; i<n; i++) cout << pai[i]+1<< " ";
		cout << endl;
	}	
	exit(0);
}
