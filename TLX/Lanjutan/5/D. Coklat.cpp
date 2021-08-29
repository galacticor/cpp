#include <bits/stdc++.h>
using namespace std;

struct name
{
	long long h;
	long long b;
}coklat[100010];

long long n,d,sum,ans;

bool cmp(name a,name b){
	return a.h<b.h;
}

int main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>coklat[i].h>>coklat[i].b;
	}
	sort(coklat+1,coklat+1+n,cmp);
	for(int i=1;i<=n;i++){
		ans=min(coklat[i].b,d/coklat[i].h);
		d-=(ans*coklat[i].h);
		sum+=ans;
	}
	cout<<sum<<endl;
	return 0;

}