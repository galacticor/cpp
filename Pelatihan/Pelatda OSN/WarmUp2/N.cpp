#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int a[50],b[50],n,m,tot,t,batas;
bool p;

void kombinasi(int depth,int prev,int sum){
	if(depth>batas){
		if(temp==m || tot-sum==m){
			p=true;
			return;
		}
	}
	else{
		for(int i=prev+1;i<=n;i++){
			return kombinasi(depth+1,i,sum+b[i]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	a[0]=0;
	for(int tc=1;tc<=t;tc++){
		p=false;
		cin>>n>>m;
		tot=0;
		for(int i=1;i<=n;i++){
			cin>>b[i];
			tot+=b[i];
		}
		for(int i=0;i<=(n+1)/2;i++){
			batas=i;
			kombinasi(0,0,0);
			if(p){
				break;
			}
			
		}
		if(p) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

	return 0;
}