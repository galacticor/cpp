#include <bits/stdc++.h>
using namespace std;

int n,a[110],b[110],sum,k,tot,res,ans[1000],l,cek[1000];
bool visited[1000],p;

int gcd(int x,int y){
	if(x==0){
		return y;
	}
	else{
		return gcd(y%x,x);
	}
}

int lcm(int x, int y){
	return (x/gcd(x,y))*y;
}


int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cek[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(cek[i]>1){
			p=true;
		}
	}
	if(p){
		cout<<"-1"<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				sum=0;
				k=a[i];
				tot=0;
				while(tot<=n){
					if(!visited[k]){
						sum++;
						tot++;
						k=a[k];
						visited[k]=true;
					}
					else{
						l++;
						if(sum%2==1){
							ans[l]=sum;
						}
						else{
							ans[l]=sum/2;
						}
						break;
					}
				}
			}
		}
		res=1;
		for(int i=1;i<=l;i++){
			res=gcd(res,ans[i]);
		}
		cout<<res<<endl;
	}
	
	return 0;
}