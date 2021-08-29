#include <bits/stdc++.h>
using namespace std;

long long n,a[100010],sum;
bool p;

int main(){
	freopen("lemonade.in","r",stdin);
	freopen("lemonade.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	sum=0;
	for(int i=1;i<=n;i++){
		if(a[n-i+1]<i-1){
			break;
		}
		else{
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;

}