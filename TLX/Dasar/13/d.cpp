#include <bits/stdc++.h>
using namespace std;
 
pair<double,int>price[100010];
int j,n,x,w[100010];
double a[100010],sum,c[100010];
 
int main(){
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[i]=c[i]/w[i];
		price[i].first=a[i];
		price[i].second=w[i];
	}
	sort(price+1,price+n+1);
	j=n;
	while(x>0 && j>0){
		if(x>=price[j].second){
			sum=sum+price[j].first*price[j].second;
			x=x-price[j].second;
		}
		else{
			sum=sum+x*price[j].first;
			x=0;
		}
		j--;
	}
	cout<<fixed<<setprecision(5);
	cout<<sum<<endl;
	return 0;
}
