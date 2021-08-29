#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

bool p[1000010],q[1000010];
ll n,a,b,ans,x,y,t;
ll gcd(int x,int y){
	if(y==0) return x;
	else return gcd(y,x%y);
}

ll lcm(int x,int y){
	return x/gcd(x,y) * y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>n>>a>>b;
		memset(p,false,sizeof(p));	
		memset(q,false,sizeof(q));
		x=lcm(a,b);
		y=min(a,b);
		for(int i=1;i<=x/y;i++){
			p[(i*a)%n]=true;
			q[(i*b)%n]=true;
			if(p[(i*a)%n]==q[(i*a)%n] || p[(i*b)%n]==q[(i*b)%n]){
				ans=i;
				break;
			}
		}
		cout<<ans<<endl;	
	}

	return 0;
}