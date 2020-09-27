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

	ll t;
	cin>>t;
	while(t!=0)
	{
		t--;
		int n;
		cin>>n;
		vector<int> v(n);

		for(int i=0;i<n;i++)
		{
			cin>>v[i];

		}

		int c=0;
		int d=0;
		int p=0;


		for(int i=0;i<n-1;i++)
		{
			if(v[i]>v[i+1]){c=i+1;}
			if(v[i]<v[i+1]){d=i+1;}
		}
		bool de=false;
		for(int i=0;i<n-1;i++)
		{
			if(v[i]>v[i+1] and de==false){de=true;}

			else if(v[i]<=v[i+1] and de==true){de=false; p=i;}

		}

		//cout << "c= " << c << " d= " << d << " p= " << p << endl;
		//cout<<min(c,min(p,d))<<endl;
		cout << p << endl;
	}
	return 0;


}
