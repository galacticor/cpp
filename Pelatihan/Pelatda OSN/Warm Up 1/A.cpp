#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int k,ans,sum;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>s>>k;
	int i=s.length()-1;
	while(i>0 && sum<k){
		if(s[i]=='0'){
			sum++;
		}
		else ans++;
		i--;
	}

	if(sum<k){
		ans=s.length()-1;
	}
	cout<<ans<<endl;

	return 0;
}