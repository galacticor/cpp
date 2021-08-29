#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

string s,a[110],s1;
int t,n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>s;
		n=s.length();
		for(int i=0;i<=n-1;i++){
			s1="";
			for(int j=i;j<=n-1+i;j++){
				s1+=s[j%n];
			}
			a[i]=s1;
		}
		sort(a,a+n);
		cout<<a[0]<<endl;
	}

	return 0;
}