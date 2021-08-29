#include <bits/stdc++.h>
using namespace std;

int n,a[100010],sum;
bool p;

int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		p=true;
		sum++;
		if(a[n-i+1]<i){
			p=false;
		}
		if(!p){
			break;
		}
	}
	cout<<sum<<endl;
	return 0;

}