#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);


typedef long long ll;

int main(){ _
	
	int n;
	vector <int> s;
	cin >> n;
	int a;
	for(int i=0; i<n; i++){
		 cin >> a;
		s.push_back(a);
	}
	
	int at=0;
	int l=0, r=n-1;	
	vector <vector < char> > total;
	vector <char> v;
	vector <char> ans;
	for(int i=0; i<n; i++){
		if(s[l]<=at and s[r]<=at){
			break;
		}
	
		if(s[l]==s[r]){
			int l_max = 1;
			while(l<n-1 and s[l]<s[l+1]){
				l++;
				l_max++;
			}
		
			int r_max = 1;
			while(r>0 and s[r]<s[r-1]){
				r--;
				r_max++;
			}
			if(l_max>r_max)
				for(int j=0; j<l_max; j++)
					v.push_back('L');
			else
				for(int j=0; j<r_max; j++)
					v.push_back('R');

			break;
		}

		if(s[r] < s[l] and s[r]>at){
			v.push_back('R');
			at = s[r];
			r--;
		}
		else if (s[l]<s[r] and s[l]>at){
			v.push_back('L');
			at = s[l];
			l++;
		}
		else{
			if(s[r]>s[l]){
				v.push_back('R');
				at = s[r];
				r--;
			}
			else{
				v.push_back('L');
				at = s[l];
				l++;
			}
		}
	}
	
	cout << v.size() << endl;
	for(int i=0; i<(int)v.size(); i++)
		cout << v[i];
	cout << endl;

	exit(0);
}
