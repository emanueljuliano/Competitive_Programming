#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n;
	while(cin >> n){
		vector<int> ent, vq, vs, vp;
		stack<int> sta;
		queue<int> que;
		priority_queue<int> pque;
		for(int i=0; i<n;i++){
			int a, b; cin >> a >> b;
			if(a==1){
				que.push(b);
				pque.push(b);
				sta.push(b);
			}
			else{
				ent.pb(b);

				vq.pb(que.front());
				que.pop();

				vp.pb(pque.top());
				pque.pop();

				vs.pb(sta.top());
				sta.pop();
			}
		}
		bool fq = vq==ent;
		bool fp = vp==ent;
		bool fs = vs==ent;

		if((fq and fp) or (fq and fs) or (fp and fs))
			cout << "not sure" << endl;
		else if(fq)
			cout << "queue" << endl;
		else if(fp)
			cout << "priority queue" << endl;
		else if(fs)
			cout << "stack" << endl;
		else
			cout << "impossible" << endl;
	}


	exit(0);
}
