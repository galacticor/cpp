#include <bits/stdc++.h>
using namespace std;

pair<int,int>temp[100010];
int n,k,sum,a,res[100010];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		temp[i].first=a;
		temp[i].second=i;
	}
	sort(temp+1,temp+n+1);
	for(int i=1;i<=n;i++){
		k=k-temp[i].first;
		if(k>=0){
			sum++;
			res[sum]=temp[i].second;
		}
		else{
			break;
		}
	}
	cout<<sum<<endl;
	for(int i=1;i<=sum;i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}
