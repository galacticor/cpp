#include <bits/stdc++.h>
using namespace std;

long long n,q,l,r,x,sum1,sum2,sum,a[100010],temp,temp1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r>>x;
		sum=0;
		sum1=0;
		sum2=0;
		if(r<=n){
			for(int j=l;j<=r;j++){
				if(a[j]==x){
					sum++;
				}
			}
			cout<<sum<<endl;
		}
		else if(r>=n && l==1){
			for(int j=1;j<=n;j++){
				if(a[j]==x){
					sum++;
				}
			}
			for(int j=1;j<=r%n;j++){
				if(a[j]==x){
					sum1++;
				}
			}
			sum=sum*(r/n)+sum1;
			cout<<sum<<endl;
		}
		else if(r>=n && l<n){
			for(int j=l;j<=n;j++){
				if(a[j]==x){
					sum++;
				}
			}
			for(int j=1;j<=n;j++){
				if(a[j]==x){
					sum1++;
				}
			}
			temp1=r%n;
			temp=(r-n)/n;
			for(int j=1;j<=temp1;j++){
				if(a[j]==x){
					sum2++;
				}
			}
			sum=sum+sum1*temp+sum2;
			cout<<sum<<endl;
		}
		else if(l>=n){
			if(r-l+1>=n){
				for(int j=l%n;j<=n;j++){
					if(a[j]==x){
						sum++;
					}
				}
				for(int j=1;j<=n;j++){
					if(a[j]==x){
						sum1++;
					}
				}
				temp1=r%n;
				temp=r/n-l/n-1;
				for(int j=1;j<=temp1;j++){
					if(a[j]==x){
						sum2++;
					}
				}
				sum=sum+sum1*temp+sum2;
				cout<<sum<<endl;
			}
			else{
				temp=r;
				while(temp>n){
					temp/=n;
				}
				for(int j=l%n;j<=temp;j++){
					if(a[j]==x){
						sum++;
					}
				}
				cout<<sum<<endl;			
			}
		}
	}

	return 0;
}