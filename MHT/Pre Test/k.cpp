#include <iostream>
using namespace std;

int n,d,a[1000010],res,x,temp,now,diff;

int main(){
	cin>>n>>d;
	int bef=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		now=x;
		if(now<=bef){
			diff=bef-now;
			res=res+diff/d+1;
			now=now+diff+d-diff%d;
		}
		
		bef=now;
		
	}
	cout<<res<<endl;
	return 0;
}
