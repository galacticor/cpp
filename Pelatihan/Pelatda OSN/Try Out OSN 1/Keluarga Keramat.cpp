#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

ll k,a,b,t,tempa,tempb;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>k>>a>>b;
		tempa=a;
		tempb=b;
		if(k==1){
			cout<<min(a,b)<<endl;
			continue;
		}
		while(tempa!=tempb){
			if(tempa>tempb){
				if(tempa%k>1){
					tempa/=k;
					tempa++;
				}
				else{
					tempa/=k;
				}
			}
			else{
				if(tempb%k>1){
					tempb/=k;
					tempb++;
				}
				else{
					tempb/=k;
				}
			}
		}
		cout<<tempa<<endl;
	}
	return 0;
}