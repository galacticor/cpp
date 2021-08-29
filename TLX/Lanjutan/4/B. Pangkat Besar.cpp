#include <bits/stdc++.h>
using namespace std;

int a,b,ans;
long long jaw,temp;
bool p;

long long fe(int x, int y){
	if(y==1){
		return x;
	}
	else{
		if(y%2==1){
			jaw=fe(x,y-1)*x;
			if(temp>=1000000){
				p=true;
			}
			return jaw%1000000;
		}
		else{
			temp=fe(x,y/2);
			jaw=temp*temp;
			if(jaw>=1000000){
				p=true;
			}
			return jaw%1000000;
		}
	}
}

int main(){
	cin>>a>>b;
	p=false;
	ans=fe(a,b)%1000000;
	if(p){
		if(ans<100000){
			cout<<"0";
		}
		if(ans<10000){
			cout<<"0";
		}
		if(ans<1000){
			cout<<"0";
		}
		if(ans<100){
			cout<<"0";
		}
		if(ans<10){
			cout<<"0";
		}
	}
	cout<<ans<<endl;
	return 0;
}