#include <bits/stdc++.h>
using namespace std;

long long iskehm[10000010],t,n,p,sum,a[10000010],temp,y;
bool fixkehm[1000000010];

void kehm(long long x){
	long long q;
	for(int i=1;i<=x;i++){
		iskehm[i]=(i-1)*i*(i+1)/6;
	}
	for(int i=1;i<=x;i++){
		for(int j=i+1;j<=x;j++){
			for(int k=j+1;k<=x;k++){
				q=iskehm[i]+iskehm[j]+iskehm[k];
				fixkehm[q]=true;
			}
		}
	}
}

int main(){
	kehm(900);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		p=0;
		sum=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		sort(a+1,a+n+1);
		for(int j=1;j<=n;j++){
			if(fixkehm[a[j]]){
				if(p>0){
					sum=sum+a[j];
					temp=sum;
					p=p+temp;	
				}
				else{
					sum=sum+a[j];
					temp=sum;
					p=p+temp;
					y=a[j];
				}
				
				
			}
		}
		if(sum==0){
			cout<<"Kasus #"<<i<<": NPC tidak mengirim paket"<<endl;
		}
		else{
			cout<<"Kasus #"<<i<<": "<<p-y<<endl;
		}
		
	}
	return 0;
}