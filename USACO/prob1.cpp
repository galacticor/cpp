#include <bits/stdc++.h>
#include <cstdio>
#include <fstream>
using namespace std;

/*
ID: galacticor
LANG: C++11
PROB: Problem 1. Blocked Billboard II
*/

int x1,ye1,x2,ye2,a1,a2,b1,b2,ans;

int main(){
	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);

	cin>>x1>>ye1>>x2>>ye2;
	cin>>a1>>b1>>a2>>b2;
	if((x1>=a1) && (x2<=a2) && (ye1>=b1) && (ye2<=b2)){
		ans=0;
	}
	else if((x1>=a1) && (x2<=a2)){
			if(ye1>=b1 && ye1<=b2){
				ans=(abs(ye2-b2)*abs(x2-x1));
			}
			else if(ye2<=b2 && ye2>=b1){
				ans=(abs(ye1-b1)*abs(x2-x1));
			}
			else{
				ans=(abs(x2-x1)*abs(ye2-ye1));
			}
	}
	else if((ye1>=b1) && (ye2<=b2)){
		if(x1>=a1 && x1<=a2){
			ans=(abs(x2-a2)*abs(ye2-ye1));
		}
		else if(x2<=a2 && x2>=a1){
			ans=(abs(x1-a1)*abs(ye2-ye1));
		}
		else{
			ans=(abs(x2-x1)*abs(ye2-ye1));
		}
	}
	else{
		ans=(abs(x2-x1)*abs(ye2-ye1));
	}
	cout<<ans<<endl;
	return 0;
}