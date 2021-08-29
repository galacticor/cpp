#include <bits/stdc++.h>
using namespace std;

int temp,b,sum,res,k,a,f,dest,y,i,x,res1,res2,res3;

int main(){
	cin>>a>>b>>f>>k;
	temp=b;
	res=0;
	dest=a*k;
	i=1;
	while(i<=k+1){
			if(i==1){
				x=f;
				y=y+x;
				b=b-x;
				if(b<0){
					res=-1;
					res1=res;
					break;
				}
			}
			else if(i==k+1){
					x=dest-y;
					b=b-x;
					if(b<0){
						b=temp-x;
						sum++;
					}
					if(b<0){
						res=-1;
						res2=res;
						break;
					}
				}
			else if(temp>=2*(a-f) && i%2==0){
				x=2*(a-f);
				y+=x;
				b=b-x;
				if(b<0){
					sum++;
					b=temp-x;
				}
			}
			else if(i%2==1 && temp>=2*f){
				x=2*f;
				y+=x;
				b=b-x;
				if(b<0){
					sum++;
					b=temp-x;
				}
			}
			else{
				res=-1;
				res3=res;
				break;
			}
		i++;
	}
	if(res!=-1){
		res=sum;
	}
	cout<<res<<endl;
}