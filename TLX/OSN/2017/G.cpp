#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

bool p[10];
int ans,n;
char c;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c=='L'){
			if(p[1]){
				ans++;
				p[1]=p[2]=p[3]=p[4]=0;
			}
			p[2]=1;
		}
		if(c=='R'){
			if(p[2]){
				ans++;
				p[1]=p[2]=p[3]=p[4]=0;
			}
			p[1]=1;
		}
		if(c=='U'){
			if(p[3]){
				ans++;
				p[1]=p[2]=p[3]=p[4]=0;
			}
			p[4]=1;
		}
		if(c=='D'){
			if(p[4]){
				ans++;
				p[1]=p[2]=p[3]=p[4]=0;
			}
			p[3]=1;
		}
	}
	cout<<ans+1<<endl;

	return 0;
}